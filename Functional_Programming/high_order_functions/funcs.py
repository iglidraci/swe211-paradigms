from functools import reduce
from typing import Any, Callable, Iterable, Iterator

first = lambda x: x[0]

def my_map(data: Iterable[Any], f: Callable[[Any], Any]) -> Iterator[Any]:
    if data:
        yield f(first(data))
        yield from my_map(data[1:], f)


def my_filter(data: Iterable[Any], f: Callable[[Any], bool]) -> Iterator[Any]:
    if data:
        if f(y := first(data)): yield y
        yield from my_filter(data[1:], f)


def my_reduce(data: Iterable[Any], f: Callable[[Any, Any], Any], init: Any = None):
    def reduce(iterator: Iterator[Any], f, current):
        try:
            return reduce(iterator, f, f(current, next(iterator)))
        except StopIteration:
            return current
    iterator = iter(data)
    try:
        value = init if init is not None else next(iterator)
        return reduce(iterator, f, value)
    except StopIteration:
        return init


if __name__ == '__main__':
    print(list(my_filter([1, 2, 3, 4, 5], lambda x: x%2==0)))
    print(list(my_map([1, 2, 3, 4, 5], lambda x: x*2)))
    assert my_reduce([1, 2, 3, 4, 5], lambda x, y: x+y) == reduce(lambda x, y: x+y, [1, 2, 3, 4, 5])
    assert my_reduce([1, 2, 3, 4, 5], lambda x, y: x*y) == reduce(lambda x, y: x*y, [1, 2, 3, 4, 5])
    assert my_reduce([1, 2, 3, 4, 5], lambda x, y: f'{x}->{y}') == reduce(lambda x, y: f'{x}->{y}', [1, 2, 3, 4, 5])

    print(my_reduce(map(lambda x: x**2, range(10)), lambda x, y: x+y))