<div align="center">
<p>
    <img width="680" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/chatbot.png">
</p>
<h1>카카오톡 챗봇 FastAPI 서버</h1>
<h3>TODO - Kafka 서버를 통한 자동 전달</h3>
<h3>TODO - 각 유저마다 last notice index</h3>

[@현재 서버 Go언어 Gin으로 변경됨](https://github.com/Alfex4936/KakaoChatBot-Golang) |
[@아주대 공지 챗봇](http://pf.kakao.com/_RUcxnK)

<a href="https://hits.seeyoufarm.com"><img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FAlfex4936%2FkakaoChatbot-Ajou&count_bg=%23000000&title_bg=%23000000&icon=wechat.svg&icon_color=%23E7E7E7&title=%3A&edge_flat=true"/></a>

<a href="http://pf.kakao.com/_RUcxnK"><img src="https://badgen.net/uptime-robot/status/m786780621-6bbd0da746df747d7b6835c8"></img></a>

</div>

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/block1.png">
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/block2.png">
</p>
<h3>block1 / block2</h3>
</div>

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/db_desc.png">
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/db_notices.png">
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/db_users.png">
</p>
<h3>AWS RDS (MySQL 모델)</h3>
</div>

## 사용
AWS EC2 + S3 + RDS
```console
ubuntu:~$ virtualenv server
ubuntu:~$ source ~/server/bin/activate

(server) ubuntu:~$ pip install fastapi uvicorn SQLAlchemy

(server) ubuntu:~$ aws s3 cp s3://bucket/kakao.py .
(server) ubuntu:~$ aws s3 cp s3://bucket/parser.py .

(server) ubuntu:~$ python parser.py
(server) ubuntu:~$ python kakao.py
INFO:     Started server process [id]
INFO:     Waiting for application startup.
INFO:     Application startup complete.
INFO:     Uvicorn running on http://0.0.0.0:8000 (Press CTRL+C to quit)
```

## 특징
* [오늘/어제 공지 불러오기](https://github.com/Alfex4936/kakaoChatbot-Ajou#%EC%98%A4%EB%8A%98%EC%96%B4%EC%A0%9C-%EA%B3%B5%EC%A7%80-%EB%B6%88%EB%9F%AC%EC%98%A4%EA%B8%B0) (ListCard 최대 한계 5개)
* [어제 공지](https://github.com/Alfex4936/kakaoChatbot-Ajou#%EC%98%A4%EB%8A%98%EC%96%B4%EC%A0%9C-%EA%B3%B5%EC%A7%80-%EB%B6%88%EB%9F%AC%EC%98%A4%EA%B8%B0)는 MySQL DB를 통해 불러온다.
* [마지막 공지 1개](https://github.com/Alfex4936/kakaoChatbot-Ajou#%EB%A7%88%EC%A7%80%EB%A7%89-%EA%B3%B5%EC%A7%80-1%EA%B0%9C-%EB%B6%88%EB%9F%AC%EC%98%A4%EA%B8%B0) 불러오기 ("마지막 공지 알려줘")
* [카테고리 선택](https://github.com/Alfex4936/kakaoChatbot-Ajou#%EA%B3%B5%EC%A7%80-%EB%B6%84%EB%A5%98) (학사,학사일정,비교과,장학, 취업,사무,행사,파란학기제,학술,입학,기타)
* [키워드 공지](https://github.com/Alfex4936/kakaoChatbot-Ajou#%EA%B3%B5%EC%A7%80-%ED%82%A4%EC%9B%8C%EB%93%9C-%EA%B2%80%EC%83%89) 검색 ("2021 검색해줘")
* [학사 일정](https://github.com/Alfex4936/kakaoChatbot-Ajou#%ED%95%99%EC%82%AC-%EC%9D%BC%EC%A0%95-%EB%B3%B4%EA%B8%B0) 보기 ("달력", "일정")
* [수원 날씨 보기](https://github.com/Alfex4936/KakaoChatBot-Golang#%EC%95%84%EC%A3%BC%EB%8C%80-%EC%A7%80%EC%97%AD-%EB%82%A0%EC%94%A8-%EB%B3%B4%EA%B8%B0) ("날씨", "우산")
* [인물 검색](https://github.com/Alfex4936/KakaoChatBot-Golang#%EC%9D%B8%EB%AC%BC-%EA%B2%80%EC%83%89) ("인물" 입력 후 번호/학과/이름 원하는대로 검색)
* [도서관 좌석 현황](https://github.com/Alfex4936/KakaoChatBot-Golang#%EB%8F%84%EC%84%9C%EA%B4%80-%EC%A2%8C%EC%84%9D-%ED%98%84%ED%99%A9) ("도서관", "좌석", 중앙 도서관 좌석이용 현황 불러옴)
* [학식 보기](https://github.com/Alfex4936/KakaoChatBot-Golang#%ED%95%99%EC%8B%9D-%EB%B6%88%EB%9F%AC%EC%98%A4%EA%B8%B0) ("오늘/내일 장소", "장소=학생,교직원,기숙사")
* [채용 정보] ("채용" 교내 채용 정보 10개를 불러옴)

## 카카오 챗봇
title, items, text... 길이를 넘기면 제대로 출력이 안될 수도 있다.

*simpleText*: text(1000)

*ListCard*: header(15), list_title(35), list_description(16), lists(5)

*Carousel*: items(10)

## 카카오 챗봇 API JSON Model
```python
class KakaoUser(BaseModel):
    id: str
    properties: Dict
    type: str


class KakaoUserRequest(BaseModel):
    block: Dict
    lang: Optional[str]
    params: Dict
    timezone: str
    user: KakaoUser
    utterance: str


class KakaoAction(BaseModel):
    clientExtra: Optional[Dict]
    detailParams: Dict
    id: str
    name: str
    params: Dict


class KakaoAPI(BaseModel):
    """Main Kakao JSON"""

    action: KakaoAction
    bot: Dict
    contexts: Optional[List]
    intent: Dict
    userRequest: KakaoUserRequest

@application.post("/route", response_model=KakaoAPI)
async def message(content: KakaoAPI):
    ...
```

## 예제 JSON 반응
"2021 검색"

INFO:     server - "POST /search HTTP/1.1" 200 OK

```json
{
    "action": {
        "clientExtra": {},
        "detailParams": {
            "sys_text": {
                "groupName": "",
                "origin": "2021",
                "value": "2021"
            }
        },
        "id": "id",
        "name": "스킬 이름",
        "params": {
            "sys_text": "2021"
        }
    },
    "bot": {
        "id": "id",
        "name": "AjouNotice"
    },
    "contexts": [],
    "intent": {
        "extra": {
            "reason": {
                "code": 1,
                "message": "OK"
            }
        },
        "id": "id",
        "name": "공지 키워드 검색"
    },
    "userRequest": {
        "block": {
            "id": "id",
            "name": "공지 키워드 검색"
        },
        "lang": "kr",
        "params": {
            "ignoreMe": "true",
            "surface": "BuilderBotTest"
        },
        "timezone": "Asia/Seoul",
        "user": {
            "id": "id",
            "properties": {
                "botUserKey": "key",
                "bot_user_key": "key"
            },
            "type": "botUserKey"
        },
        "utterance": "2021 검색\n"
    }
}
```

## [오늘/어제 공지 불러오기](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L548)

POST = /message | 발화 =
"어제 공지 알려줘", 
"오늘 공지 알려줘"...

entity = "when"

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/yesterday.png">
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/today.png">
</p>
</div>

## [오늘 공지 더보기](https://github.com/Alfex4936/KakaoChatBot-Golang/blob/main/controllers/getNotice.go#L109)

POST = /today2

"오늘" 공지에서 더보기를 누르면 10개 정도의 공지를 더 불러옵니다.

(5개 이하일 시 아주대 홈피로 이동됨)

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/more_notices.jpg">
</p>
</div>

## [마지막 공지 1개 불러오기](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L428)

POST = /last |
 발화 = "지난 공지 알려줘", 
"마지막 공지"...

entity = 

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/last_notice.png">
</p>
</div>

## [공지 분류](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L301)

POST = /ask |
 발화 = "카테고리", 
"분류"...

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/category.png">
</p>
</div>

## [공지 키워드 검색](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L460)

POST = /search |
 발화 = "카테고리", 
"분류"...

entity = 분류 필요

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/keyword_search.png">
</p>
</div>

## [학사 일정 보기](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L572)

POST = /schedule |
 발화 = "달력", "일정" ...

entity = 분류 필요

TO-DO: Selenium을 통한 자동 db 업데이트

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/schedule.png">
</p>
</div>

## [아주대 지역 날씨 보기](https://github.com/Alfex4936/KakaoChatBot-Golang/blob/main/controllers/infomation.go#L26)

(수원 영통구 날씨를 weather.naver.com에서 불러옴)

POST = /info/weather2 |
 발화 = "날씨", "아주대 날씨", "날씨 좋아?" ...

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/weather.jpg">
</p>
</div>

## [인물 검색](https://github.com/Alfex4936/KakaoChatBot-Golang/blob/main/controllers/infomation.go#L65)

POST = /info/prof |
 발화 = "인물"

 "인물" 입력 후 키워드 검색

TO-DO: 더 나은 발화문

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/search.jpg">
</p>
</div>

## [도서관 좌석 현황](https://github.com/Alfex4936/KakaoChatBot-Golang/blob/main/controllers/infomation.go#L109)
POST = /info/library |
 발화 = "도서관", "좌석"

 발화문 입력 시 중앙도서관 좌석 이용 현황을 불러옵니다.

TO-DO: 더 나은 메시지 포맷

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/library.jpg">
</p>
</div>

## [학식 불러오기](https://github.com/Alfex4936/KakaoChatBot-Golang/blob/main/controllers/infomation.go#L135)
POST = /info/meal |
 발화 = "오늘 학식", "내일 학생", "내일 교직원", "내일 기숙사" ...

 오늘/내일 장소를 입력하면 시간에 맞는 장소의 학식 정보를 불러옵니다.

TO-DO: 더 나은 메시지 포맷

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/meal.png">
</p>
</div>