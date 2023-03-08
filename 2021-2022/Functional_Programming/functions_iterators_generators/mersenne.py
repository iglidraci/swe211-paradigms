from typing import Callable

class Mersenne:
    '''
    A class following the Strategy design pattern depends on other objects to provide an
    algorithm or parts of an algorithm. This allows us to inject algorithmic details at runtime,
    rather than compiling the details into the class
    '''
    def __init__(self, algorithm: Callable[[int], int]) -> None:
        self.pow2 = algorithm

    def __call__(self, arg: int) -> int:
        return self.pow2(arg) - 1


# let's have a look at a couple of candidates for power of 2

def shifty(x: int) -> int:
    return 1 << x

def multiply(x: int) -> int:
    if x == 0: return 1
    return 2 * multiply(x-1)

def faster(x: int) -> int:
    if x == 0: return 1
    if x % 2 == 0:
        return (y:=faster(x//2)) * y
    else:
        return (y:=faster(x//2)) * y * 2


m1 = Mersenne(shifty)
m2 = Mersenne(multiply)
m3 = Mersenne(faster)
m4 = Mersenne(lambda x: 2**x)

for nr in range(50):
    assert (m1(nr) == m2(nr) == m3(nr) == m4(nr))