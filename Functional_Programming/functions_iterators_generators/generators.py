'''
- Generators appear to be sequence-like
- Generators can be used only once. After that, they appear empty
'''

from math import sqrt
from typing import Iterator


def infinity() -> Iterator[int]:
    # noisy function since we are keeping a state and mutating it
    i = 0
    while True:
        yield i
        i += 1
 
def prime_factors(n: int) -> Iterator[int]:
    '''
    locate prime factors of a number N
    if N is even, yield 2 and then recursively find all prime factors of n/2
    if N is odd, we'll step through odd values greater than or equal to 3
    if we can't locate a factor, the number N, must be prime
    '''
    if n % 2 == 0:
        yield 2
        if n//2 > 1:
            yield from prime_factors(n//2)
        return
    else:
        for i in range(3, int(sqrt(n) + 0.5) + 1, 2):
            if n % i == 0:
                yield i
                if n // i > 1:
                    yield from prime_factors(n//i)
                return
    yield n

'''
yield from is used to consume iterable values from the recursive call
DO NOT use return recursive_call(args)
'''

'''
the following is a more purely recursive version
'''

def rec_prime_factors(n: int) -> Iterator[int]:
    def factor_n(n: int, x: int) -> Iterator[int]:
        if x*x > n:
            yield n
            return
        if n % x == 0:
            yield x
            if n//x > 1:
                yield from factor_n(n//x, x)
        else:
            yield from factor_n(n, x+2)
    if n % 2 == 0:
        yield 2
        if n // 2 > 1:
            yield from rec_prime_factors(n//2)
        return
    yield from factor_n(n, 3)


print(list(prime_factors(6998)))
print(list(rec_prime_factors(6998)))

result = rec_prime_factors(6998)
# print(len(result)) # cannot do this, cannot call len() function on a generator
# another limitation of generator functions is that they can only be used once
print(sum(result))
print(sum(result)) # this should print zero since we consumed all the values

res2 = rec_prime_factors(6998)
print(next(res2))
print(next(res2))