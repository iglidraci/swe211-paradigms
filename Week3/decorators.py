from datetime import datetime


def function(num):
    def first():
        return "Hi, my name is"

    def second():
        return "Chika-chika Slim Shady"

    if num == 1:
        return first
    elif num == 2:
        return second
    else:
        return lambda: 'Bye kids!'  # anonymous function


def my_decorator(func):
    def wrapper():
        print("exec sth before actually calling the function.")
        func()
        print("after the function is called.")

    return wrapper


def send_email():
    print("Dear all")


def during_the_day(func):
    def wrapper():
        if not 7 <= datetime.now().hour <= 23.55:
            func()
        else:
            # you better go to sleep
            pass

    return wrapper


def do_twice(func):
    def wrapper(*args, **kwargs):
        func(*args, **kwargs)
        func(*args, **kwargs)
    return wrapper


@during_the_day
def study():
    print("studying ...")


@during_the_day
@do_twice
def take_meds():
    print('taking meds ...')


@do_twice
def present_yourself(name, greeting):
    print(f'{greeting}, I\'m {name}')


def main():
    nr = int(input("which function do you want to call?\n"))
    func = function(nr)
    print(func())
    send = my_decorator(send_email)
    send()
    # decorators wrap a function, modifying its behavior.
    # syntactic sugar
    study()
    take_meds()
    present_yourself('igli', 'hello')


if __name__ == '__main__':
    main()
