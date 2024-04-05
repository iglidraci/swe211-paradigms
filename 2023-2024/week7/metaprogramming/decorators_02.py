def decorator(func):
    def wrapper():
        print('pre-work ...')
        func()
        print('post-work ...')
    return wrapper


@decorator
def run():
    print('running ...')


def do_twice(func):
    def wrapper_do_twice(*args, **kwargs):
        func(*args, **kwargs)
        func(*args, **kwargs)
    return wrapper_do_twice


@do_twice
def take_meds(drug):
    print(f'take {drug}')


# create a decorator that can cache return values of a function
def memo(func):
    def wrapper_memo(*args, **kwargs):
        key = (*args, *(kwargs.items()))
        if key in cache:
            return cache[key]
        else:
            res = func(*args, **kwargs)
            cache[key] = res
            return res

    cache = {}
    return wrapper_memo


@memo
def fib(n):
    if n in (0, 1):
        return n
    return fib(n-1) + fib(n-2)


if __name__ == '__main__':
    # run()
    take_meds('pill')
    print(fib(100))
