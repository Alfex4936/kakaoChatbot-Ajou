<div align="center">
<p>
    <img width="680" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/chatbot.png">
</p>
<h1>카카오톡 챗봇 FastAPI 서버</h1>
<h3>TODO - Kafka 서버를 통한 자동 전달</h3>

[@아주대 공지 챗봇](http://pf.kakao.com/_RUcxnK)

<a href="https://hits.seeyoufarm.com"><img src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FAlfex4936%2FkakaoChatbot-Ajou&count_bg=%23000000&title_bg=%23000000&icon=wechat.svg&icon_color=%23E7E7E7&title=%3A&edge_flat=true"/></a>

</div>

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/block1.png">
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/block2.png">
</p>
<h3>block1 / block2</h3>
</div>

## 사용
AWS EC2 + S3 기준
```console
ubuntu:~$ virtualenv server
ubuntu:~$ source ~/server/bin/activate

ubuntu:~$ pip install fastapi
ubuntu:~$ pip install uvicorn

(server) ubuntu:~$ aws s3 cp s3://bucket/kakao.py .
(server) ubuntu:~$ python kakao.py
INFO:     Started server process [id]
INFO:     Waiting for application startup.
INFO:     Application startup complete.
INFO:     Uvicorn running on http://0.0.0.0:8000 (Press CTRL+C to quit)
```

## 특징
* 오늘/어제 공지 불러오기 (ListCard 최대 한계 5개)
* 마지막 공지 1개 불러오기 ("마지막 공지 알려줘")
* 카테고리 선택 (학사,학사일정,비교과,장학, 취업,사무,행사,파란학기제,학술,입학,기타)
* 키워드 공지 검색 ("2021 검색해줘")

## 카카오 챗봇
title, items, text... 길이를 넘기면 제대로 출력이 안될 수도 있다.

*simpleText*: text(1000)

*ListCard*: header(15), list_title(35), list_description(16), lists(5)

## 예제 JSON 반응
"2021 검색"

INFO:     server - "POST /search HTTP/1.1" 200 OK

```json
{'action': {'clientExtra': {},
            'detailParams': {'sys_text': {'groupName': '',
                                          'origin': '2021',
                                          'value': '2021'}},
            'id': 'id',
            'name': '스킬 이름',
            'params': {'sys_text': '2021'}},
 'bot': {'id': 'id', 'name': 'AjouNotice'},
 'contexts': [],
 'intent': {'extra': {'reason': {'code': 1, 'message': 'OK'}},
            'id': 'id',
            'name': '공지 키워드 검색'},
 'userRequest': {'block': {'id': 'id',
                           'name': '공지 키워드 검색'},
                 'lang': 'kr',
                 'params': {'ignoreMe': 'true', 'surface': 'BuilderBotTest'},
                 'timezone': 'Asia/Seoul',
                 'user': {'id': 'id',
                          'properties': {'botUserKey': 'key',
                                         'bot_user_key': 'key'},
                          'type': 'botUserKey'},
                 'utterance': '2021 검색\n'}}
```

## [오늘/어제 공지 불러오기](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L443)

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

## [마지막 공지 1개 불러오기](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L327)

POST = /last |
 발화 = "지난 공지 알려줘", 
"마지막 공지"...

entity = 

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/last_notice.png">
</p>
</div>

## [공지 분류](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L205)

POST = /ask |
 발화 = "카테고리", 
"분류"...

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/category.png">
</p>
</div>

## [공지 키워드 검색](https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/kakao.py#L358)

POST = /search |
 발화 = "카테고리", 
"분류"...

entity = 분류 필요

<div align="center">
<p>
    <img width="300" src="https://github.com/Alfex4936/kakaoChatbot-Ajou/blob/main/imgs/keyword_search.png">
</p>
</div>