from data import *

is_zero = lambda x: x(lambda y: false)(true)

if __name__ == '__main__':
    assert is_zero(zero) is true
    assert is_zero(one) is false