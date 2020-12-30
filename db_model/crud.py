from sqlalchemy.orm import Session

from . import models


def get_user_by_user_id(db: Session, user_id: str):
    return (
        db.query(models.Users).filter(models.Users.user_id == user_id).first()
    )  # returns None or db object


def get_user_last_notice(db: Session, user_id: str):
    user = db.query(models.Users).filter(models.Users.user_id == user_id).first()
    return user.last_notice_id


def create_user(db: Session, user_id: str):
    db_user = models.Users(user_id=user_id, last_notice_id=10000,)
    db.add(db_user)
    db.commit()
    db.refresh(db_user)
    return db_user


def create_notice(db: Session, id: int, title: str, date: str, link: str, writer: str):
    db_notice = models.Notices(id=id, title=title, date=date, link=link, writer=writer)
    db.add(db_notice)
    db.commit()
    db.refresh(db_notice)
    return db_notice


def get_notice_by_id(db: Session, notice_id: int):
    return (
        db.query(models.Notices).filter(models.Notices.id == notice_id).first()
    )  # returns None or db object


def update_last_notice(db: Session, user_id: str, last_notice_id: int):
    db_user = get_user_by_user_id(db=db, user_id=user_id)
    if db_user.last_notice_id < last_notice_id:
        db_user.last_notice_id = last_notice_id
        db.commit()
        db.refresh(db_user)
    return db_user


def get_notices_with_date(db: Session, date: str):
    notices = (
        db.query(models.Notices)
        .filter(models.Notices.date == date)
        .order_by(models.Notices.id.desc())
        .all()
    )
    return notices  # read notices by descending order


def delete_old_notice(db: Session, date: str):
    delete = models.Notices.__table__.delete().where(models.Notices.date == date)
    db.execute(delete)
    db.commit()
