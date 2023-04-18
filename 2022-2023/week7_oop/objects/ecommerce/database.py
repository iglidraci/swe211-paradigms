from typing import Optional


class Database:
    def __init__(self, connection: Optional[str] = None) -> None:
        pass


db: Optional[Database] = None


def get_database(connection: str) -> Database:
    global db
    if not db:
        db = Database(connection)
    return db
