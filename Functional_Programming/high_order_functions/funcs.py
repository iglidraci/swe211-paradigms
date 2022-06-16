from functools import reduce
from typing import Any, Callable, Iterable, Iterator

first = lambda x: x[0]

def my_map(data: Iterable[Any], f: Callable[[Any], Any]) -> Iterator[Any]:
    pass


def my_filter(data: Iterable[Any], f: Callable[[Any], bool]) -> Iterator[Any]:
    pass


def my_reduce(data: Iterable[Any], f: Callable[[Any, Any], Any], init: Any = None):
    pass


if __name__ == '__main__':
    print(list(my_filter([1, 2, 3, 4, 5], lambda x: x%2==0)))
    print(list(my_map([1, 2, 3, 4, 5], lambda x: x*2)))
    assert my_reduce([1, 2, 3, 4, 5], lambda x, y: x+y) == reduce(lambda x, y: x+y, [1, 2, 3, 4, 5])
    assert my_reduce([1, 2, 3, 4, 5], lambda x, y: x*y) == reduce(lambda x, y: x*y, [1, 2, 3, 4, 5])
    assert my_reduce([1, 2, 3, 4, 5], lambda x, y: f'{x}->{y}') == reduce(lambda x, y: f'{x}->{y}', [1, 2, 3, 4, 5])

    print(my_reduce(map(lambda x: x**2, range(10)), lambda x, y: x+y))