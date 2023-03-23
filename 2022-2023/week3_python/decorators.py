import time
from datetime import datetime


# first-class functions
def run(name):
    return f'{name} is running'


def play(name):
    return f'{name} is playing'


def foo_does(action_func):
    return action_func('Foo')


# returning functions
def parent(nr):
    def first_child():
        return 'Child 1'

    def second_child():
        return 'Child 2'

    if nr == 1:
        return first_child
    elif nr == 2:
        return second_child
    else:
        return lambda: 'Unknown'


def decorator(func):
    def wrapper():
        print('doing some work before calling the function ...')
        func()
        print('doing some work after calling the function')
    return wrapper


def mornings_only(func):
    def wrapper():
        if not 7 <= datetime.now().hour <= 10:
            func()
        else:
            print('Sorry, to late to send an email')
    return wrapper


def do_twice(func):
    def wrapper_do_twice(*args, **kwargs):
        func(*args, **kwargs)
        func(*args, **kwargs)
    return wrapper_do_twice


@mornings_only
def send_email():
    print('Welcome to Programming Language Paradigms')


@do_twice
def take_meds():
    print('taking a pill')


@do_twice
def greet(name):
    print(f'hello {name}')


# what if you want to return something from your function?
# create a decorator that supports returning


# create a decorator called timeit to measure the time a function takes to execute
# use time.pref_counter() to measure a short duration
def timeit(func):
    """measure the runtime of a decorated function"""
    pass


@timeit
def sum_squares_up_to(n):
    return sum([i**2 for i in range(1, n+1)])


# create a debug decorator that will print the arguments a function is called with as well as its return value
def debug(func):
    pass


@debug
def factorial(n):
    if n in (0, 1):
        return 1
    return n * factorial(n-1)


def e(term=20):
    # approximate e
    return sum([1/factorial(x) for x in range(term)])


# create a decorator that can cache return values of a function
def memo(func):
    pass


@memo
def fib(n):
    if n in (0, 1):
        return n
    return fib(n-1) + fib(n-2)


if __name__ == '__main__':
    print(foo_does(run))
    print(foo_does(play))
    # first = parent(1)
    # second = parent(2)
    # unknown = parent(3)
    # print(first)
    # send_email()
    # take_meds()
    # greet('Foo')
    # print(sum_squares_up_to(10**3))
    # print(factorial(3))
    # print(e())
    # print(fib(100))
