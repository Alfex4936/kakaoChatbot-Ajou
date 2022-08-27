from sqlalchemy import Column, Integer, String

from .database import Base


class Notices(Base):
    __tablename__ = "ajou_notices"

    id = Column(Integer, primary_key=True, unique=True)
    title = Column(String(100))
    category = Column(String(5))
    date = Column(String(30))
    link = Column(String(101))
    writer = Column(String(25))


class Users(Base):
    __tablename__ = "users"

    user_id = Column(String(100), primary_key=True, unique=True)
    last_notice_id = Column(Integer)


class Schedules(Base):
    __tablename__ = "ajou_sched"

    id = Column(Integer, primary_key=True)
    content = Column(String(50))
    start_date = Column(String(12))
    end_date = Column(String(12))
