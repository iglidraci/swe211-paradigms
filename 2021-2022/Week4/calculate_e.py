def debug(func):
    def wrapper(*args, **kwargs):
        print(f'calling {func.__name__} with {args}')
        res = func(*args, **kwargs)
        print(f'result is {res}')
        return res
    return wrapper


def tail_factorial(n, accumulator):
    if n <= 1:
        return accumulator
    else:
        return tail_factorial(n-1, accumulator*n)


@debug
def factorial(n):
    return tail_factorial(n, 1)


def calc_e(terms=20):
    """
    e = sum (1/n!) for n from 0 -> infinity
    """
    return sum([1/factorial(n) for n in range(terms)])


if __name__ == '__main__':
    print(f'e = {calc_e()}')
