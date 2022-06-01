# function that takes two arguments and always returns the second argument
zero = lambda x: lambda y: y
# apply the x function to y
one = lambda x: lambda y: x(y)
# apply function x twice
two = lambda x: lambda y: x(x(y))

increment = lambda x: x + 1     # illegal in terms of lambda calculus, just as a starting point

# if we apply function zero to any function, it will behave as identity function
identity = zero(increment)  # zero doesn't care about the first arg, it will always return the second arg

increment_one = one(increment)

increment_twice = two(increment)

successor = lambda w: (lambda y: lambda x: y(w(y)(x))) # w(y)(x) is the old number

# successor of function zero should be the function one
new_one = successor(zero)
new_increment_one = new_one(increment_one)


# successor of function new_one should be the function two
new_two = successor(new_one)
new_increment_twice = new_two(increment)


three = successor(new_two)
increment_thrice = three(increment)


new_three = successor(successor(successor(zero)))
new_increment_thrice = new_three(increment)


weird = three(three)


LAMBDAS = lambda x: 'λ'+x


if __name__ == "__main__":
    print(identity(0), identity(1))
    print(increment_one(1), increment_one(4))
    print(increment_twice(3))
    # successor
    print(new_increment_one(100) == increment_one(100))
    print(new_increment_twice(22) == increment_twice(22))
    print(increment_thrice(301))
    print(increment_thrice(200) == new_increment_thrice(200))
    # what could be the result
    print(weird(increment)(0))
    print(three(LAMBDAS)(''))
    