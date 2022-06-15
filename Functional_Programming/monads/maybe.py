from typing import List


class Maybe:
    
    def __init__(self, value):
        self.value = value

    @classmethod
    def unit(cls, value):
        return cls(value)

    def map(self, f):
        if self.value is None:
            return self
        new_value = f(self.value)
        return Maybe.unit(new_value)


first = lambda x: x[0]


class User:
    def __init__(self, name: str, friends: List["User"]):
        self.name = name
        self.friends = friends


class Request:
    def __init__(self, user: User):
        self.user = user


if __name__ == '__main__':
    me = User("Me", None)
    foo = User("Foo", None)
    bar = User("Bar", None)
    baz = User("Baz", [me, foo])
    qux = User("Qux", [bar, baz])
    quux = User("Quux", [qux, baz])
    corge = User("Corge", [quux, baz])
    request = Request(user=corge)
    friends_of_first_friends = (
        Maybe.unit(request)
        .map(lambda request: request.user)
        .map(lambda user: user.friends)
        .map(first)
        .map(lambda first_friend: first_friend.friends)
    )
    print(list(map(lambda x: x.name, friends_of_first_friends.value)))