import ssl
from urllib.error import HTTPError, URLError
from urllib.request import urlopen

from selectolax.parser import HTMLParser
from typed_python import Class, Final, Forward, ListOf, Member


class Homepage:
    __slots__ = ()

    @staticmethod
    def checkConnection():
        """홈페이지 반응을 체크한다."""
        context = ssl._create_unverified_context()
        try:
            urlopen(
                url="https://www.ajou.ac.kr/kr/ajou/notice.do",
                timeout=2.0,
                context=context,
            )
        except HTTPError:
            print("Seems like the server is down now.")
            return False
        except URLError:
            print("Seems like the url is wrong now.")
            return False
        except TimeoutError:
            print("It's taking too long to load website.")
            return False
        return True  # the connection automatically is closed

    @staticmethod
    def parseNotices(url=None, length=10):
        ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"

        """공지 파서 메인

        Args:
            url (str, optional): 홈페이지 URL (with admin options). Defaults to None.
            length (int, optional): 몇 개의 공지를 읽을 것인가. Defaults to 10.

        Returns:
            ids, posts, dates, writers, length (list, optional): length에 따른 공지 목록을 전부 불러온다.
        """
        if url is None:
            url = f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=0"

        context = ssl._create_unverified_context()
        try:
            result = urlopen(url, timeout=2.0, context=context)
        except HTTPError:
            print("Seems like the server is down now.")
            return None, 0  # make entity
        except TimeoutError:
            print("It's taking too long to load website.")
            return None, 0  # make entity

        html = result.read().decode("utf-8")
        soup = HTMLParser(html)
        no_post = soup.css_first("td.b-no-post")
        if no_post:
            return None, 0  # make entity

        ids = soup.css("td.b-num-box")
        posts = soup.css("div.b-title-box > a")
        # links will be generated by posts[i] href
        dates = soup.css("span.b-date")
        writers = soup.css("span.b-writer")
        length = len(ids)

        ids = soup.css("td.b-num-box")
        posts = soup.css("div.b-title-box > a")
        dates = soup.css("span.b-date")
        writers = soup.css("span.b-writer")

        notices = ListOf(Notice)()

        for i in range(length):
            title = posts[i].text(strip=True)
            writer = writers[i].text(strip=False)

            duplicate = "[" + writer + "]"
            if duplicate in title:  # writer: [writer] title
                title = title.replace(duplicate, "").strip()  # -> writer: title

            notice = Notice(
                ids[i].text(strip=True),
                title,
                dates[i].text(strip=True),
                writer,
                ADDRESS + posts[i].attributes["href"],
            )
            notices.append(notice)

        return notices, length


init = Forward("ClassWithInit")


@init.define
class Notice(Class, Final):
    # __slots__ = ("_id", "_post", "_date", "_link", "_writer")
    _id = Member(str)
    _post = Member(str)
    _date = Member(str)
    _writer = Member(str)
    _link = Member(str)

    def __init__(self, id, post, date, writer, link):
        self._id = id
        self._post = post
        self._date = date
        self._writer = writer
        self._link = link

    def getAttrs(self, *attrs):
        result = [None] * len(attrs)
        if not attrs:
            return result

        for i, attr in enumerate(attrs):
            result[i] = getattr(self, attr)

        return result

    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, id):
        self._id = id

    @property
    def title(self):
        return self._post

    @title.setter
    def title(self, title):
        self._post = title

    @property
    def date(self):
        return self._date

    @date.setter
    def date(self, date):
        self._date = date

    @property
    def writer(self):
        return self._writer

    @writer.setter
    def writer(self, writer):
        self._writer = writer

    @property
    def link(self):
        return self._link

    @link.setter
    def link(self, link):
        self._link = link


if __name__ == "__main__":
    notice = Notice("2020", "title", "date", "writer", "link")
