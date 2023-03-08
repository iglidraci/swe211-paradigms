# we can represent TRUE and FALSE
true = lambda x: lambda y: x  # always return the first value
false = lambda x: lambda y: y  # always return the second value

# we'll start naming functions with underscore _ to avoid python keywords

_not = lambda x: x(false)(true)

# AND ≡ λxy.xy(λuv.v)
# if x is true, then give me what ever is y, in other words true(y)(x)
# if x is false, then give me x
# function
_and = lambda x: lambda y: x(y)(x)
# _and = lambda x: lambda y: x(y)(false)

# OR ≡ λxy.x(λuv.u)y
# if x is true, then give me x
# if x is false, then give me y

_or = lambda x: lambda y: x(x)(y)
# _or = lambda x: lambda y: x(true)(y)


if __name__ == '__main__':
    print(true('5V')('0V'))
    print(false('5V')('0V'))
    assert _not(true) is false
    assert _not(false) is true
    assert _or(true)(true) is true
    assert _or(true)(false) is true
    assert _or(false)(true) is true
    assert _or(false)(false) is false
    assert _and(true)(true) is true
    assert _and(true)(false) is false
    assert _and(false)(true) is false
    assert _and(false)(false) is false
