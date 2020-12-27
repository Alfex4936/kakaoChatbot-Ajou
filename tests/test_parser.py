import json
import ssl
from urllib.error import HTTPError, URLError
from urllib.request import urlopen

from bs4 import BeautifulSoup


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


def parser(url=f"{ADDRESS}?mode=list&&articleLimit={LENGTH}&article.offset=0"):
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
    dates = soup.select("table > tbody > tr > td.b-td-left > div > div > span.b-date")
    writers = soup.select(
        "table > tbody > tr > td.b-td-left > div > div.b-m-con > span.b-writer"
    )
    return ids, posts, dates, writers


# Test #1
def test_parse():
    assert checkConnection() == True

    ids, posts, dates, writers = parser()
    assert len(ids) == 10, f"Check your parser: {ids}"
    assert len(posts) == 10, f"Check your parser: {posts}"
    assert len(dates) == 10, f"Check your parser: {dates}"
    assert len(writers) == 10, f"Check your parser: {writers}"
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


def test_connection():
    assert checkConnection() == True
    assert checkConnection(ADDRESS + ":/") == False


if __name__ == "__main__":
    test_parse()
    # print(next(iter(read["POSTS"].keys())))  # Last Key
