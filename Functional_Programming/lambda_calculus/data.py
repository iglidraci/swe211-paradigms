from bool import *
from numbers import *

# A pair (a, b) can be represented in λ-calculus using function (λz.zab)
build = lambda x: lambda y: lambda s: s(x)(y)   # like a tuple
first = lambda x: x(true)
second = lambda x: x(false)

_tuple = lambda x: (x[0]+1, x[0])
_tuple2 = lambda x: build(successor(first(x)))(first(x))
predecessor = lambda x: second(x(_tuple2)(build(zero)(zero)))
subtract = lambda x: lambda y: y(predecessor)(x)

if __name__ == '__main__':
    data = build(10)(20)
    print(data(true), data(false))
    print(first(data))
    print(second(data))
    linked_list = build(1)(build(2)(build(3)(4)))
    print(first(linked_list))
    print(first(second(second(linked_list))))
    print(three(_tuple)((0, 0)))
    pair = three(_tuple2)(build(zero)(zero))
    print(first(pair)(increment)(0))
    print(predecessor(one)(increment)(0))
    twenty_seven = three(three)
    twenty_six = predecessor(twenty_seven)
    print(twenty_six(increment)(0))
    twenty_five = subtract(twenty_seven)(two)
    print(twenty_five(increment)(0))