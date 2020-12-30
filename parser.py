import ssl
import time
from contextlib import contextmanager
from datetime import datetime, timedelta
from urllib.error import HTTPError
from urllib.request import urlopen

import db_model.crud
import db_model.database
import db_model.models
import db_model.schemas
from bs4 import BeautifulSoup


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
                print("Trying to parse new posts...")
                ids, posts, dates, writers = self.parser()  # 다시 파싱
                while ids is None:  # 파싱이 안되면 5분마다 다시 시도
                    time.sleep(300)
                    ids, posts, dates, writers = self.parser()

                for i in range(self.LENGTH):
                    postId = ids[i].text.strip()
                    isDuplicated = False
                    with get_db() as db:
                        if db_model.crud.get_notice_by_id(db=db, notice_id=postId):
                            isDuplicated = True
                    if isDuplicated:
                        continue
                    postLink = self.ADDRESS + posts[i].get("href")
                    postTitle = posts[i].text.strip()
                    postDate = dates[i].text.strip()
                    postWriter = writers[i].text

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
            return None, None, None, None  # make entity
        except TimeoutError:
            print("It's taking too long to load website.")
            return None, None, None, None  # make entity

        html = result.read()
        soup = BeautifulSoup(html, "html.parser")
        ids = soup.select("table > tbody > tr > td.b-num-box")
        posts = soup.select("table > tbody > tr > td.b-td-left > div > a")
        dates = soup.select(
            "table > tbody > tr > td.b-td-left > div > div > span.b-date"
        )
        writers = soup.select(
            "table > tbody > tr > td.b-td-left > div > div.b-m-con > span.b-writer"
        )
        return ids, posts, dates, writers


if __name__ == "__main__":
    ajou = AjouParser()
    ajou.run()
