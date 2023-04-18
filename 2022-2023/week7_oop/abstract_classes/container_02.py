
"""
Container class has exactly one abstract method that needs to be implemented, __contains__()
This __contains__() special method implements the Python in operator
"""
from collections.abc import Container


class OddIntegers:
    def __contains__(self, x: int) -> bool:
        return x % 2 != 0


if __name__ == '__main__':
    odd = OddIntegers()
    print(isinstance(odd, Container))
    print(1 in odd)
    print(2 in odd)
    print()
