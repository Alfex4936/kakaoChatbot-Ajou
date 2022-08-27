import ssl
import time
from contextlib import contextmanager
from dataclasses import dataclass
from datetime import datetime, timedelta
from enum import Enum
from typing import List, Optional
from urllib.error import HTTPError
from urllib.parse import quote
from urllib.request import urlopen

from pytz import timezone
from selectolax.parser import HTMLParser

import db_model.crud
import db_model.database
import db_model.models
import db_model.schemas

db_model.models.Base.metadata.create_all(bind=db_model.database.engine)

# Dependency
@contextmanager
def get_db():
    db = db_model.database.SessionLocal()
    try:
        yield db
    finally:
        db.close()


class Error(Enum):
    TIMEOUT = 1
    INVALID_URL = 2
    NO_NOTICE = 3
    INVALID_CATEGORY = 4


@dataclass
class Notice:
    id: int
    title: str
    category: str
    writer: str
    date: str
    link: str


class NoticeFilter:
    BASIC_URL = "https://www.ajou.ac.kr/kr/ajou/notice.do?mode=list&article.offset=0&articleLimit=15"

    CATEGORIES = {
        "학사": 1,
        "비교과": 2,
        "장학": 3,
        "학술": 4,
        "입학": 5,
        "취업": 6,
        "사무": 7,
        "기타": 8,
        "행사": 166,
        "파란학기제": 167,
        "파란학기": 167,
        "학사일정": 168,
    }

    __slots__ = ("nums", "category", "keyword")

    def __init__(
        self,
        /,
        nums: Optional[int] = 15,
        category: Optional[int | str] = None,
        keyword: Optional[str] = "",
    ):
        self.nums = nums
        self.category = category
        self.keyword = keyword

    def build(self) -> str:
        if self.keyword is None:
            self.keyword = ""
        if self.category is None:
            self.category = ""

        return f"https://www.ajou.ac.kr/kr/ajou/notice.do?mode=list&srSearchKey=&srSearchVal={quote(self.keyword.strip())}&article.offset=0&srCategoryId={self.category}&articleLimit={self.nums}"

    def set_number_of_notice(self, num: int) -> None:
        self.nums = num

    def set_category(self, category: str) -> Optional[Error]:
        try:
            self.category = self.CATEGORIES[category]
        except Exception:
            # print("잘못된 카테고리입니다.")
            self.category = ""
            return Error.INVALID_CATEGORY

        return None

    def set_keyword(self, keyword: str) -> None:
        self.keyword = keyword

    def __repr__(self) -> str:
        return self.build()


class Ajou:
    """
    Ajou notices Parser (MySQL)

    Methods
    -------
    run()

    Usage
    -----
        ajou = AjouParser(Kafka_server_ip, mysql_db_name)
        ajou.run()
    """

    ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"
    LENGTH = 15

    __slots__ = ()

    def __init__(self):
        print("Initializing...")

    def run(self, period=1800):  # period (second)
        """Check notices from html per period"""
        try:
            while True:  # 30분마다 무한 반복
                now = datetime.now(timezone("Asia/Seoul"))
                week = now.weekday()
                if week >= 5:  # for saturday, sunday
                    monday = datetime(
                        now.year,
                        now.month,
                        now.day,
                        9,
                        0,
                        tzinfo=timezone("Asia/Seoul"),
                    )
                    monday += timedelta(days=7 - week)
                    diff_secs = (monday - now).seconds
                    print(
                        f"Weekend...resting until next KST monday 9am: {diff_secs//60} minutes",
                    )
                    time.sleep(diff_secs)
                elif (
                    now.hour >= 19 or 0 <= now.hour <= 8
                ):  # after 7pm, rest until next morning 10am
                    nextMorning = datetime(
                        now.year,
                        now.month,
                        now.day,
                        10,
                        0,
                        tzinfo=timezone("Asia/Seoul"),
                    )
                    if now.hour >= 19:
                        nextMorning += timedelta(days=1)
                    diff_secs = (nextMorning - now).seconds
                    print(
                        f"Night time...resting until next KST 9am: {diff_secs//60} minutes"
                    )
                    time.sleep(diff_secs)
                    continue  # possible weekend

                print("Trying to parse new posts...")
                notices = self.parser()  # 다시 파싱
                while notices is Error:  # 파싱이 안되면 5분마다 다시 시도
                    time.sleep(300)
                    notices = self.parser()

                for notice in notices:  # type: ignore
                    isDuplicated = False
                    with get_db() as db:
                        if db_model.crud.get_notice_by_id(db=db, notice_id=notice.id):
                            isDuplicated = True
                    if isDuplicated:
                        continue

                    with get_db() as db:
                        db_model.crud.create_notice(
                            db=db,
                            id=notice.id,
                            title=notice.title,
                            category=notice.category,
                            date=notice.date,
                            link=notice.link,
                            writer=notice.writer,
                        )

                print("Parsed at", self.getTimeNow())
                print(f"Resting 30 minute...")
                time.sleep(period)
        except Exception as e:  # General exceptions
            print(e)
            print(dir(e))
        except KeyboardInterrupt:
            print("Pressed CTRL+C...")
        finally:
            print("\nExiting...")

    @staticmethod
    def getTimeNow() -> datetime:
        return datetime.now()

    # Ajou notices parser
    def parser(
        self, url: Optional[str] = None, filter: Optional[NoticeFilter] = None
    ) -> List[Notice] | Error:
        if filter is None:
            filter = NoticeFilter()

        if url is not None:
            url = url
        else:
            url = filter.build()
        context = ssl._create_unverified_context()
        try:
            result = urlopen(url, timeout=3.0, context=context)
        except HTTPError:
            # print("Seems like the server is down now.")
            return Error.INVALID_URL
        except TimeoutError:
            # print("It's taking too long to load website.")
            return Error.TIMEOUT

        html = result.read().decode("utf-8")
        soup = HTMLParser(html)
        no_post = soup.css("td.b-no-post")
        if no_post:
            return Error.NO_NOTICE

        notices: List[Notice] = []

        ids = soup.css("td.b-num-box")
        posts = soup.css("div.b-title-box > a")
        cates = soup.css("span.b-cate")
        dates = soup.css("span.b-date")
        writers = soup.css("span.b-writer")

        for i in range(len(ids)):
            id = ids[i].text(strip=True)
            try:
                id = int(id)
            except Exception:  # 공지
                continue

            title = posts[i].text(strip=True)
            writer = writers[i].text(strip=False)
            category = cates[i].text(strip=True)

            duplicate = "[" + writer + "]"
            if duplicate in title:  # writer: [writer] title
                title = title.replace(duplicate, "").strip()  # -> writer: title
            duplicate = " 자세히 보기"
            if duplicate in title:  # writer: [writer] title
                title = title.replace(duplicate, "").strip()  # -> writer: title

            date = dates[i].text(strip=True)
            link = self.ADDRESS + str(posts[i].attributes["href"])

            notices.append(Notice(id, title, category, writer, date, link))

        if not notices:
            return Error.NO_NOTICE

        return notices


if __name__ == "__main__":
    ajou = Ajou()
    # print(ajou.parser())

    filter = NoticeFilter(nums=10)
    filter.set_category("학사d")
    filter.set_keyword("졸업")
    print(ajou.parser(filter=filter))

    # print(filter.build())
