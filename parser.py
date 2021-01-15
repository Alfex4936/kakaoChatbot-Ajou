import ssl
import time
from contextlib import contextmanager
from datetime import datetime, timedelta
from pytz import timezone
from urllib.error import HTTPError
from urllib.request import urlopen

import db_model.crud
import db_model.database
import db_model.models
import db_model.schemas
from selectolax.parser import HTMLParser

db_model.models.Base.metadata.create_all(bind=db_model.database.engine)

# Dependency
@contextmanager
def get_db():
    db = db_model.database.SessionLocal()
    try:
        yield db
    finally:
        db.close()


class AjouParser:
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
                ids, posts, dates, writers, length = self.parser()  # 다시 파싱
                while length == 0:  # 파싱이 안되면 5분마다 다시 시도
                    time.sleep(300)
                    ids, posts, dates, writers, length = self.parser()

                for i in range(length):
                    postId = ids[i].text(strip=True)
                    isDuplicated = False
                    with get_db() as db:
                        if db_model.crud.get_notice_by_id(db=db, notice_id=int(postId)):
                            isDuplicated = True
                    if isDuplicated:
                        continue
                    postTitle = posts[i].text(strip=True)
                    postLink = self.ADDRESS + posts[i].attributes["href"]
                    postDate = dates[i].text(strip=True)
                    postWriter = writers[i].text(strip=False)

                    duplicate = "[" + postWriter + "]"
                    if duplicate in postTitle:  # writer: [writer] title
                        postTitle = postTitle.replace(
                            duplicate, ""
                        ).strip()  # -> writer: title

                    with get_db() as db:
                        db_model.crud.create_notice(
                            db=db,
                            id=int(postId),
                            title=postTitle,
                            date=postDate,
                            link=postLink,
                            writer=postWriter,
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
    def parser(self, url=None):
        if url is None:
            url = (
                f"{self.ADDRESS}?mode=list&&articleLimit={self.LENGTH}&article.offset=0"
            )
        # req = requests.get(f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0")
        context = ssl._create_unverified_context()
        try:
            result = urlopen(url, timeout=2.0, context=context)
        except HTTPError:
            print("Seems like the server is down now.")
            return None, None, None, None, 0  # make entity
        except TimeoutError:
            print("It's taking too long to load website.")
            return None, None, None, None, 0  # make entity

        html = result.read().decode("utf-8")
        soup = HTMLParser(html)
        no_post = soup.css("td.b-no-post")
        if no_post:
            return None, None, None, None, 0  # make entity

        ids = soup.css("td.b-num-box")
        posts = soup.css("div.b-title-box > a")
        dates = soup.css("span.b-date")
        writers = soup.css("span.b-writer")
        return ids, posts, dates, writers, len(ids)


if __name__ == "__main__":
    ajou = AjouParser()
    ajou.run()
