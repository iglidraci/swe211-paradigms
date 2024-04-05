class Foo:
    def __init__(self) -> None:
        self.x = 1     # public attribute
        # By convention, we prefix an internal attribute or method with _ to signify protected
        self._y = 2
        # Double underscore, __, will perform name mangling on the attribute in question ("private")
        self.__z = 3


if __name__ == '__main__':
    f = Foo()
    print(f.x)
    print(f._y)
    # print(f.__z)