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

if __name__ == '__main__':
    print(increment_twice(20))
    print(new_increment_twice(20))
    print(increment_100_times(1))
