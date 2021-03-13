class Kjson:
    __slots__ = ()

    @staticmethod
    def buildCard(postId, postTitle, postDate, postLink, postWriter, putDate=False):
        """리스트 카드형의 카드 형식"""
        duplicate = "[" + postWriter + "]"
        if duplicate in postTitle:  # writer: [writer] title
            postTitle = postTitle.replace(duplicate, "").strip()  # -> writer: title

        if putDate:
            postWriter = f"{postWriter} {postDate[len(postDate) -5:]}"

        return {
            "title": (postTitle[:33] + "..") if len(postTitle) > 35 else postTitle,
            "description": postWriter,
            # "imageUrl": "http://k.kakaocdn.net/dn/APR96/btqqH7zLanY/kD5mIPX7TdD2NAxgP29cC0/1x1.jpg",
            "link": {"web": postLink},
        }

    @staticmethod
    def buildSimpleText(msg, quickReplies=None):
        data = {
            "version": "2.0",
            "template": {"outputs": [{"simpleText": {"text": msg}}],},  # max len = 1000
        }

        if quickReplies is not None:
            data["template"]["quickReplies"] = quickReplies
        return data

    @staticmethod
    def buildListCard(title, items, buttons, quickReplies=None):
        data = {
            "version": "2.0",
            "template": {
                "outputs": [
                    {
                        "listCard": {
                            "header": {"title": title},
                            "items": items,
                            "buttons": buttons,
                        }
                    }
                ],
            },
        }
        if quickReplies is not None:
            data["template"]["quickReplies"] = quickReplies
        return data

