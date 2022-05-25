from numbers import *

add = lambda x: lambda y: y(successor)(x)

multiply = lambda x: lambda y: lambda z: x(y(z))


_print = lambda x: print(x(increment)(0))   # illegal in lambda calculus but just for simplicity

_print(add(two)(three))

if __name__ == '__main__':
    print(add(two)(three)(increment)(0))
    print(multiply(three)(three)(increment)(0))