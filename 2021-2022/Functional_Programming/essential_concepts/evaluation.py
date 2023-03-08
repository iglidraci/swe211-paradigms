'''
Functional programming's efficiency stems, in part, from being able to defer a computation
until it's required
In Python, outside the logical operators, an expression is evaluated eagerly from left to right
'''

False and print("Hello World 1")
False or print("Hello World 2")

# generator expressions and generator functions are lazy

def numbers():
    for i in range(1024):
        print(f'->{i}')
        yield i


# noisy function but just to look at our lazy evaluation
def sum_to(n: int) -> int:
    s: int = 0
    for i in numbers():
        s += i
        if i == n: break
    return s


print(sum_to(4))