class Foo:
    def __init__(self) -> None:
        self.x: int = 1     # public attribute
        # By convention, we prefix an internal attribute or method with _ to signify protected
        self._y: int = 2
        # Double underscore, __, will perform name mangling on the attribute in question ("private")
        self.__z: int = 3


if __name__ == '__main__':
    f = Foo()
    print(f.x)
    print(f._y)