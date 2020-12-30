from pydantic import BaseModel


class NoticeInfo(BaseModel):
    id: int
    title: str
    date: str
    link: str
    writer: str

    class Config:
        orm_mode = True


class UserInfo(BaseModel):
    user_id: str
    last_notice_id: int

    class Config:
        orm_mode = True
