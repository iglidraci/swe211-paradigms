from numbers import successor, increment, two, three

#  If we want to add say 2 and 3, we just apply the successor function two times to 3
# basically two successors of 3
add = lambda x: lambda y: y(successor)(x)
two_plus_three = two(successor)(three)

# multiply x and y
# (λxyz.x(yz))
multiply = lambda x: lambda y: lambda z: y(x(z))
three_times_three = lambda z: three(three(z))


# the only reason why we're using increment(0) is to see the result, so just create a function
_print = lambda x: print(x(increment)(0))   # illegal in lambda calculus but just for simplicity


if __name__ == '__main__':
    print(add(two)(three)(increment)(0))
    print(multiply(three)(three)(increment)(0))
    print(two_plus_three(increment)(0))
    print(three_times_three(increment)(0) == multiply(three)(three)(increment)(0))
    _print(three_times_three)