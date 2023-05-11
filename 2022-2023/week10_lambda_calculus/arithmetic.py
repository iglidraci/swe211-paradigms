"""
Let us try the following in order to compute 2+3:
2S3 ≡ (λsz.s(sz))(λwyx.y(wyx))(λuv.u(u(uv)))
"""
from numbers import two, successor, increment

three = successor(two)
five = two(successor)(three)
increment_by_5 = five(increment)

#  If we want to add say 2 and 3, we just apply the successor function two times to 3
# basically two successors of 3
add = lambda x: lambda y: y(successor)(x)

ten = add(five)(five)
_20 = add(ten)(ten)
incr_10 = ten(increment)
incr_20 = _20(increment)

"""
The multiplication can be computed through the function (λxyz.x(yz))
"""

multiply = lambda x: lambda y: lambda z: x(y(z))

_400 = multiply(_20)(_20)
incr_400 = _400(increment)

if __name__ == '__main__':
    print(increment_by_5(100))
    print(incr_10(100))
    print(incr_20(100))
    print(incr_400(100))
