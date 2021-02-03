import json
import ssl
from urllib.error import HTTPError, URLError
from urllib.request import urlopen

from bs4 import BeautifulSoup
from selectolax.parser import HTMLParser
from memory_profiler import profile

""" 아주대학교 공지 HTML 옵션

> 보기 옵션
articleLimit= 10 (10개만 불러오기)
article.offset= 0  (시작 index)

> 검색 옵션
srCategoryId= { "학사": 1, "학사일정": 168, "비교과": 2,
                "장학": 3, "취업": 6, "사무": 7,
                "행사": 166, "파란학기제": 167, "학술": 4,
                "입학": 5, "기타": 8,
              } 
srSearchKey= article_title (제목), article_text (내용), etcChar6 (공지 부서)
srSearchVal= 2021 (키워드)
"""

ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"
LENGTH = 10
FILTER_WORDS = ("설문", "기프트", "납부", "등록금")  # only parse if notices contain these words


def checkConnection(url=ADDRESS):
    context = ssl._create_unverified_context()
    try:
        urlopen(url, timeout=2.0, context=context)
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


# Make data into dictionary format
def makeJson(postId, postTitle, postDate, postLink, postWriter):
    duplicate = "[" + postWriter + "]"
    if duplicate in postTitle:  # writer: [writer] title
        postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title
    return {
        postId: {
            "TITLE": postTitle,
            "DATE": postDate,
            "LINK": ADDRESS + postLink,
            "WRITER": postWriter,
        }
    }


def makeJsonModel(notice):
    return {
        notice.id: {
            "TITLE": notice.post,
            "DATE": notice.date,
            "LINK": notice.link,
            "WRITER": notice.writer,
        }
    }


@profile
def parser_modest(url=f"{ADDRESS}?mode=list&articleLimit={LENGTH}&article.offset=0"):
    # req = requests.get(f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0")
    context = ssl._create_unverified_context()
    try:
        result = urlopen(url, timeout=10.0, context=context)
    except HTTPError:
        print("Seems like the server is down now.")
        return None, None, None, None, 0  # make entity
    except TimeoutError:
        print("It's taking too long to load website.")
        return None, None, None, None, 0  # make entity

    html = result.read().decode("utf-8")
    soup = HTMLParser(html)
    no_post = soup.css_first("td.b-no-post")
    if no_post:
        return None, None, None, None, 0  # make entity

    ids = soup.css("td.b-num-box")
    posts = soup.css("div.b-title-box > a")
    dates = soup.css("span.b-date")
    writers = soup.css("span.b-writer")
    return ids, posts, dates, writers, len(ids)


@profile
def parser_modest_model(
    url=f"{ADDRESS}?mode=list&articleLimit={LENGTH}&article.offset=0",
):
    # req = requests.get(f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0")
    context = ssl._create_unverified_context()
    try:
        result = urlopen(url, timeout=10.0, context=context)
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
    dates = soup.css("span.b-date")
    writers = soup.css("span.b-writer")
    length = len(ids)

    result = [
        Notice(ids[i], posts[i], dates[i], writers[i]) for i in range(length)
    ]  # memory
    return result, length


def parser_soup(url=f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0"):
    # req = requests.get(f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0")
    context = ssl._create_unverified_context()
    try:
        result = urlopen(url, timeout=10.0, context=context)
    except HTTPError:
        print("Seems like the server is down now.")
        return None, None, None, None, 0  # make entity
    except TimeoutError:
        print("It's taking too long to load website.")
        return None, None, None, None, 0  # make entity

    html = result.read().decode("utf-8")
    soup = BeautifulSoup(html, "html.parser")
    no_post = soup.select("table > tbody > tr > td.b-no-post")
    if no_post:
        return None, None, None, None, 0  # make entity

    ids = soup.select("table > tbody > tr > td.b-num-box")
    posts = soup.select("table > tbody > tr > td.b-td-left > div > a")
    dates = soup.select("table > tbody > tr > td.b-td-left > div > div > span.b-date")
    writers = soup.select(
        "table > tbody > tr > td.b-td-left > div > div.b-m-con > span.b-writer"
    )
    return ids, posts, dates, writers, len(ids)


def tester(url="https://www.ajou.ac.kr/kr/ajou/notice-calendar.do?mode=mList",):
    from selenium import webdriver
    from selenium.webdriver.chrome.options import Options

    options = Options()
    options.add_argument("--headless")

    driver = webdriver.Chrome("E:\\SDK\\chromedriver_87.0.4280.88.exe", options=options)
    driver.get("https://www.ajou.ac.kr/kr/ajou/notice-calendar.do")
    result = driver.page_source
    driver.close()

    # req = requests.get(f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0")
    # context = ssl._create_unverified_context()
    # try:
    #     result = urlopen(url, timeout=2.0, context=context)
    # except HTTPError:
    #     print("Seems like the server is down now.")
    #     return None  # make entity
    # except TimeoutError:
    #     print("It's taking too long to load website.")
    #     return None  # make entity

    from pprint import pprint as p

    html = result

    soup = HTMLParser(html)
    today = soup.css_first("p.board-calendar-day")
    sched = (
        soup.css_first("div.b-sche-box").css_first("ul.board-calendar-list").css("li")
    )
    test = []
    print(today.html)
    for s in sched:
        print(s.html)
    return sched


# Test #1
def test_parse_soup():
    # assert checkConnection() == True

    ids, posts, dates, writers, length = parser_soup()
    assert length == LENGTH, f"Check your parser: {length}"
    for i in range(LENGTH):
        postTitle = posts[i].text.strip()
        postId = ids[i].text.strip()
        postLink = posts[i].get("href")
        postDate = dates[i].text.strip()
        postWriter = writers[i].text
        assert postId is not None, f"postId is None."
        assert postLink is not None, f"postLink is None."
        assert postTitle is not None, f"postTitle is None."
        assert postDate is not None, f"postDate is None."
        assert postWriter is not None, f"postWriter is None."

        data = makeJson(postId, postTitle, postDate, postLink, postWriter)
        temp = json.dumps(data[postId])
        print("data", json.loads(temp))


@profile
def test_parse_modest():
    # assert checkConnection() == True

    ids, posts, dates, writers, length = parser_modest()
    assert length == LENGTH, f"Check your parser: {length}"
    for i in range(LENGTH):
        postTitle = posts[i].text(strip=True)
        postId = ids[i].text(strip=True)
        postLink = posts[i].attributes["href"]
        postDate = dates[i].text(strip=True)
        postWriter = writers[i].text(strip=False)
        assert postId is not None, f"postId is None."
        assert postLink is not None, f"postLink is None."
        assert postTitle is not None, f"postTitle is None."
        assert postDate is not None, f"postDate is None."
        assert postWriter is not None, f"postWriter is None."

        data = makeJson(postId, postTitle, postDate, postLink, postWriter)
        temp = json.dumps(data[postId])
        # print("data", json.loads(temp))


@profile
def test_parse_modest_model():
    assert checkConnection() == True

    notices, length = parser_modest_model()
    assert length == LENGTH, f"Check your parser: {length}"
    for i in range(LENGTH):
        data = makeJsonModel(notices[i])
        temp = json.dumps(data[notices[i].id])
        # print("data", json.loads(temp))


def test_connection():
    assert checkConnection() == True
    assert checkConnection(ADDRESS + ":/") == False


class Notice:
    ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"

    __slots__ = ("id", "post", "date", "link", "writer")

    def __init__(self, id, post, date, writer):
        self.id = id
        self.post = post
        self.date = date
        self.link = None
        self.writer = writer

        self.make_data()

    def make_data(self):
        self.id = self.id.text(strip=True)
        self.link = self.ADDRESS + self.post.attributes["href"]
        self.writer = self.writer.text(strip=False)
        self.post = self.post.text(strip=True)
        duplicate = "[" + self.writer + "]"
        if duplicate in self.post:  # writer: [writer] title
            self.post = self.post.replace(duplicate, "").strip()  # -> writer: title
        self.date = self.date.text(strip=True)


if __name__ == "__main__":
    from timeit import default_timer
    from memory_profiler import memory_usage

    # print("Soup")
    # start = default_timer()
    # parser_soup(f"{ADDRESS}?mode=list&articleLimit=10&article.offset=0")
    # print(f"{default_timer() - start:.5f}s")

    # print("Modest")
    # start = default_timer()
    # parser_modest(f"{ADDRESS}?mode=list&articleLimit=10&article.offset=0")
    # print(f"{default_timer() - start:.5f}s"

    test_parse_modest()
    test_parse_modest_model()
    # print(next(iter(read["POSTS"].keys())))  # Last Key
