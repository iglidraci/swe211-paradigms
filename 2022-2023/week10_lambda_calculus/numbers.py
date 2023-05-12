# zero can be defined as λs.(λz.z)
zero = lambda s: lambda z: z
'''
1 ≡ λsz.s(z)
2 ≡ λsz.s(s(z))
3 ≡ λsz.s(s(s(z)))
'''
one = lambda s: lambda z: s(z)
two = lambda s: lambda z: s(s(z))

# successor function S ≡ λwyx.y(wyx)
successor = lambda w: lambda y: lambda x: y(w(y)(x))

increment = lambda x: x + 1     # illegal in terms of lambda calculus

increment_twice = two(increment)
new_two = successor(one)
new_increment_twice = new_two(increment)

# illegal in terms of lambda calculus, but just to see the result
hundred = zero
for _ in range(100):
    hundred = successor(hundred)

increment_100_times = hundred(increment)

# the only reason why we're using increment(0) is to see the result, so just create a function
print_nr = lambda x: print(x(increment)(0))   # illegal in lambda calculus but just for simplicity

LAMBDAS = lambda x: 'λ'+x

three = successor(two)

inf = lambda x: x(x)


if __name__ == '__main__':
    print(increment_twice(20))
    print(successor(one)(increment)(0))
    print(hundred)
    print_nr(hundred)
    # inf(inf)  # a lambda function that diverges
    print(new_increment_twice(20))
    print(increment_100_times(1))
    print_nr(hundred)
    print(three(LAMBDAS)('a'))
    print(three(LAMBDAS)('a'))
    print(three(three)(LAMBDAS)(''))
    # print_nr(two(three)(two)(two))    # huge number 2**64
