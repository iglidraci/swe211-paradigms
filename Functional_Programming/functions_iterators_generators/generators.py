'''
- Generators appear to be sequence-like
- Generators can be used only once. After that, they appear empty
'''
from typing import Iterator


def infinity() -> Iterator[int]:
    # noisy function since we are keeping a state and mutating it
    i = 0
    while True:
        yield i
        i += 1

inf = infinity()


print(next(inf))
print(next(inf))
print(next(inf))

# for item in infinity():
#     print(item)

squared_generator = (x**2 for x in range(10**10))

print(squared_generator)
print(next(squared_generator))
print(next(squared_generator))

squared_list = [x**2 for x in range(10**10)]
print(len(squared_list))