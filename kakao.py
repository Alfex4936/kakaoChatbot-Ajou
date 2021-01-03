import ssl
from contextlib import contextmanager
from datetime import datetime, timedelta
from pprint import pprint
from typing import Dict
from urllib.error import HTTPError, URLError
from urllib.parse import quote
from urllib.request import urlopen

import db_model.crud
import db_model.database
import db_model.models
import db_model.schemas
import uvicorn
from bs4 import BeautifulSoup
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import JSONResponse


ADDRESS = "https://www.ajou.ac.kr/kr/ajou/notice.do"

db_model.models.Base.metadata.create_all(bind=db_model.database.engine)
application = FastAPI(
    title="Ajou notices server", description="for Kakao Chatbot", version="1.0.0"
)
application.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
    allow_credentials=True,
)


# Dependency
@contextmanager
def get_db():
    db = db_model.database.SessionLocal()
    try:
        yield db
    finally:
        db.close()


def checkUserDB(user_id: str):
    with get_db() as db:
        user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
        if user is None:
            user = db_model.crud.create_user(db=db, user_id=user_id)
    return user


def checkLastNotice(user_id: str):
    with get_db() as db:
        user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
        if user is None:
            user = db_model.crud.create_user(db=db, user_id=user_id)
        last_id = user.last_notice_id
    return last_id


def updateLastNotice(user_id: str, notice_id: int):
    with get_db() as db:
        user = db_model.crud.get_user_by_user_id(db=db, user_id=user_id)
        if user is None:
            user = db_model.crud.create_user(db=db, user_id=user_id)
        user = db_model.crud.update_last_notice(
            db=db, user_id=user_id, last_notice_id=notice_id
        )
    return user


def parseNotices(url=None, length=10):
    """공지 파서 메인

    Args:
        url (str, optional): 홈페이지 URL (with admin options). Defaults to None.
        length (int, optional): 몇 개의 공지를 읽을 것인가. Defaults to 10.

    Returns:
        ids, posts, dates, writers (list, optional): length에 따른 공지 목록을 전부 불러온다.
    """
    if url is None:
        url = f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=0"

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

    noticeLength = len(ids)
    return ids, posts, dates, writers, noticeLength


def checkConnection():
    """ 홈페이지 반응을 체크한다. """
    context = ssl._create_unverified_context()
    try:
        urlopen(ADDRESS, timeout=2.0, context=context)
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


def makeJSON(postId, postTitle, postDate, postLink, postWriter):
    """리스트 카드형의 카드 형식"""
    return {
        "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
        "description": postWriter,
        # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
        "link": {"web": postLink},
    }


def makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter):
    """리스트 카드형의 카드 형식, writer뒤에 날짜를 넣어준다."""
    return {
        "title": (postTitle[:32] + "...") if len(postTitle) > 35 else postTitle,
        "description": f"{postWriter} {postDate[len(postDate) -5:]}",  # 다산학부대학교학팀 12.25 (maxLength=16)
        # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
        "link": {"web": postLink},
    }


def makeTimeoutMessage():
    """ checkConnection() 결과 False, 아래 JSON 데이터를 return"""
    return JSONResponse(
        content={
            "version": "2.0",
            "template": {
                "outputs": [
                    {
                        "simpleText": {
                            "text": "아주대학교 홈페이지 서버 반응이 늦고 있네요. 잠시 후 다시 시도해보세요."
                        }
                    }
                ],  # max len = 1000
            },
        }
    )


def getTodayNotices(now, user_id):
    """ 15개 정도의 공지 목록을 읽고, 날짜에 맞는 것만 return"""
    noticesToday = []
    length = 15

    ids, posts, dates, writers, noticeLength = parseNotices(
        length=length
    )  # Parse notices
    if (
        dates[-1].text.strip() == now
    ):  # if last one is today's notice, it should load more notices
        ids2, posts2, dates2, writers2, noticeLength2 = parseNotices(
            url=f"{ADDRESS}?mode=list&articleLimit={length}&article.offset=1",
            length=length,
        )  # Load more 15 notices at offset 1
        ids += ids2
        posts += posts2
        dates += dates2
        writers += writers2
        noticeLength += noticeLength2

    for i in range(noticeLength):
        postDate = dates[i].text.strip()
        if postDate != now:
            break  # don't have to check other notices
        postTitle = posts[i].text.strip()
        postId = ids[i].text.strip()
        postLink = ADDRESS + posts[i].get("href")
        postWriter = writers[i].text

        duplicate = "[" + postWriter + "]"
        if duplicate in postTitle:  # writer: [writer] title
            postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title

        data = makeJSON(postId, postTitle, postDate, postLink, postWriter)
        noticesToday.append(data)

    updateLastNotice(user_id, int(ids[0].text.strip()))

    return noticesToday


def getYesterdayNotices(now):
    """ 어제 공지는 MySQL 데이터베이스를 통해 읽어온다. """
    with get_db() as db:
        db_notices = db_model.crud.get_notices_with_date(db=db, date=now)

    notices = []
    for notice in db_notices:
        data = makeJSON(
            notice.id, notice.title, notice.date, notice.link, notice.writer
        )
        notices.append(data)

    return notices  # descending ordered notices


def getLastNotice():
    """ 마지막 1개의 공지만 읽어온다. """
    ids, posts, dates, writers, _ = parseNotices(length=1)  # Parse one notice
    postDate = dates[0].text.strip()
    postTitle = posts[0].text.strip()
    postId = ids[0].text.strip()
    postLink = ADDRESS + posts[0].get("href")
    postWriter = writers[0].text

    duplicate = "[" + postWriter + "]"
    if duplicate in postTitle:  # writer: [writer] title
        postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title

    data = makeJSON(postId, postTitle, postDate, postLink, postWriter)
    return data, postDate


def switch(when, now, user_id):
    """ 오늘/어제 공지에 따른 옵션 switch """
    DAY = "오늘" if when == "today" else "이전"
    notices = getTodayNotices(now, user_id) if DAY == "오늘" else getYesterdayNotices(now)
    if not notices:
        notices = [
            {
                "title": "공지가 없습니다!",
                "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
            }
        ]

    data = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "listCard": {
                        "header": {"title": f"{now}) {DAY} 공지"},
                        "items": notices[:5],
                        "buttons": [
                            {"label": "공유하기", "action": "share"},
                            {
                                "label": f"{len(notices) - 5}개 더보기"
                                if len(notices) > 5
                                else "아주대학교 공지",
                                "action": "webLink",
                                "webLinkUrl": "https://www.ajou.ac.kr/kr/ajou/notice.do",
                            },
                        ],
                    }
                }
            ],
            "quickReplies": [
                {"messageText": "어제 공지 보여줘", "action": "message", "label": "어제"},
                {"messageText": "오늘 공지 보여줘", "action": "message", "label": "오늘"},
            ],
        },
    }
    return data


@application.get("/")
def hello():
    return "Welcome, the server is running well."


@application.post("/ask")
def askKeyword(_: Dict):
    """원하는 공지 분류를 선택하도록 유도"""
    # user_id = content["userRequest"]["user"]["id"]  # user Id
    # checkUserDB(user_id)
    print(">>> /ask")

    categories = [
        "학사",
        "학사일정",
        "비교과",
        "장학",
        "취업",
        "사무",
        "행사",
        "파란학기제",
        "학술",
        "입학",
        "기타",
    ]
    replies = [
        {"messageText": category, "action": "message", "label": category}
        for category in categories
    ]

    data = {
        "version": "2.0",
        "template": {
            "outputs": [{"simpleText": {"text": "무슨 공지를 보고 싶으신가요?"}}],
            "quickReplies": replies,
        },
    }

    return JSONResponse(content=data)


@application.post("/date")
def searchDate(content: Dict):
    """WIP"""
    print(">>> /date")
    print(content["action"]["params"]["date"])
    return JSONResponse(content={})


@application.post("/ask/filter")
def searchKeyword(content: Dict):
    """유저가 카테고리를 선택하도록 유도한다. 메시지 type: ListCard"""
    user_id = content["userRequest"]["user"]["id"]  # user Id
    checkUserDB(user_id)
    print(">>> /ask/filter")
    # pprint(content)
    print(content["action"]["params"]["cate"])

    if not checkConnection():
        return makeTimeoutMessage()

    length = 5

    categories = {
        "학사": 1,
        "학사일정": 168,
        "비교과": 2,
        "장학": 3,
        "취업": 6,
        "사무": 7,
        "행사": 166,
        "파란학기제": 167,
        "파란학기": 167,
        "학술": 4,
        "입학": 5,
        "기타": 8,
    }

    user_category = content["action"]["params"]["cate"].replace(
        " ", ""
    )  # remove whitespace

    url = f"{ADDRESS}?mode=list&srCategoryId={categories[user_category]}&srSearchKey=&srSearchVal=&articleLimit={length}&article.offset=0"

    ids, posts, dates, writers, noticeLength = parseNotices(
        url, length
    )  # Parse notices
    if ids is None:
        return makeTimeoutMessage()
    notices = []

    for i in range(noticeLength):
        postDate = dates[i].text.strip()
        postTitle = posts[i].text.strip()
        postId = ids[i].text.strip()
        postLink = ADDRESS + posts[i].get("href")
        postWriter = writers[i].text

        duplicate = "[" + postWriter + "]"
        if duplicate in postTitle:  # writer: [writer] title
            postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title

        data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)
        notices.append(data)

    updateLastNotice(user_id, int(ids[0].text.strip()))

    data = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "listCard": {
                        "header": {"title": f"{user_category} 공지"},
                        "items": notices[:5],
                        "buttons": [
                            {"label": "공유하기", "action": "share"},
                            {
                                "label": user_category,
                                "action": "webLink",
                                "webLinkUrl": f"https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srCategoryId={categories[user_category]}",
                            },
                        ],
                    }
                }
            ],
            # "quickReplies": [
            #     {"messageText": "어제 공지 보여줘", "action": "message", "label": "어제"},
            #     {"messageText": "오늘 공지 보여줘", "action": "message", "label": "오늘"},
            # ],
        },
    }

    return JSONResponse(content=data)


@application.post("/last")
def parseOne(content: Dict):
    """지난 최근 마지막 공지 1개만 읽어온다. 메시지 type: ListCard"""
    user_id = content["userRequest"]["user"]["id"]  # user Id
    checkUserDB(user_id)
    print("/last")
    if not checkConnection():
        return makeTimeoutMessage()

    notice, date = getLastNotice()

    data = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "listCard": {
                        "header": {"title": f"{date} 공지"},
                        "items": [notice],
                        "buttons": [{"label": "공유하기", "action": "share"},],
                    }
                }
            ],
            # "quickReplies": [
            #     {"messageText": "어제 공지 보여줘", "action": "message", "label": "어제"},
            #     {"messageText": "오늘 공지 보여줘", "action": "message", "label": "오늘"},
            # ],
        },
    }
    return JSONResponse(content=data)


@application.post("/search")
def searchNotice(content: Dict):
    """유저의 키워드에 맞는 공지를 불러온다. 메시지 type: simpleText | ListCard"""
    user_id = content["userRequest"]["user"]["id"]  # user Id
    checkUserDB(user_id)

    print(">>> /search")
    if not checkConnection():
        return makeTimeoutMessage()

    pprint(content)
    content = content["action"]["params"]
    if not "sys_text" in content:
        return JSONResponse(
            content={
                "version": "2.0",
                "template": {
                    "outputs": [{"simpleText": {"text": "2021 검색과 같이 검색어를 같이 입력하세요."}}],
                    "quickReplies": [
                        {
                            "messageText": "2021 검색",
                            "action": "message",
                            "label": "2021 검색",
                        },
                    ],
                },
            }
        )
    keyword = content["sys_text"]
    length = 7
    url = f"{ADDRESS}?mode=list&srSearchKey=&srSearchVal={quote(keyword.strip())}&articleLimit={length}&article.offset=0"

    ids, posts, dates, writers, noticeLength = parseNotices(
        url, length
    )  # Parse notices
    if ids is None:
        return JSONResponse(
            content={
                "version": "2.0",
                "template": {
                    "outputs": [{"simpleText": {"text": f"{keyword}에 관한 글이 없어요."}}],
                },
            }
        )
    notices = []

    for i in range(noticeLength):
        postDate = dates[i].text.strip()
        postTitle = posts[i].text.strip()
        postId = ids[i].text.strip()
        postLink = ADDRESS + posts[i].get("href")
        postWriter = writers[i].text

        duplicate = "[" + postWriter + "]"
        if duplicate in postTitle:  # writer: [writer] title
            postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title

        data = makeJSONwithDate(postId, postTitle, postDate, postLink, postWriter)
        notices.append(data)

    updateLastNotice(user_id, int(ids[0].text.strip()))

    data = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "listCard": {
                        "header": {"title": f"{keyword[:12]} 결과"},
                        "items": notices[:5],
                        "buttons": [
                            {"label": "공유하기", "action": "share"},
                            {
                                "label": "더보기" if len(notices) > 5 else "홈페이지 보기",
                                "action": "webLink",
                                "webLinkUrl": f"https://www.ajou.ac.kr/kr/ajou/notice.do&?mode=list&srSearchKey=&srSearchVal={quote(keyword)}",
                            },
                        ],
                    }
                }
            ],
            "quickReplies": [
                {"messageText": "등록금 검색", "action": "message", "label": "등록금 검색"},
                {"messageText": "이벤트 검색", "action": "message", "label": "이벤트 검색"},
                {"messageText": "코로나 검색", "action": "message", "label": "코로나 검색"},
            ],
        },
    }

    return JSONResponse(content=data)


@application.post("/message")
def message(content: Dict):
    """어제/오늘 공지 불러오기 위한 route | 메시지 type: ListCard """
    user_id = content["userRequest"]["user"]["id"]  # user Id
    checkUserDB(user_id)
    print(">>> /message")
    if not checkConnection():
        return makeTimeoutMessage()

    # data = content["userRequest"]["utterance"] 발화문
    when = content["action"]["params"]["when"]

    now = datetime.now()
    if when == "today":
        now = now.strftime("%y.%m.%d")
    elif when == "yesterday":
        now = now - timedelta(days=1)
        now = now.strftime("%y.%m.%d")

    response_data = switch(when, now, user_id)

    return JSONResponse(content=response_data)


if __name__ == "__main__":
    uvicorn.run(application, host="0.0.0.0", port=8000, log_level="info")
