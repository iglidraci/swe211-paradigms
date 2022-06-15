'''
return the factorial of a number
'''

from funcs import my_reduce


def factorial(nr: int) -> int:
    return my_reduce(range(1, nr+1), lambda x, y: x*y)

assert factorial(6) == 720