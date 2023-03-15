# we can define default args
# we can pass a variable number of arguments (*args, **kwargs)

def foo(_id, *args, **kwargs):
    """simple function to test variable length arguments"""
    print(f'id: {_id}')
    for arg in args:
        print(f'arg: {arg}')
    for k, v in kwargs.items():
        print(f'k: {k}, v: {v}')


foo(1, 2, 3, 'hello', state='Albania', name=4, age=60)


# guess the output
def swap(a, b):
    a = a + b
    b = a - b
    a = a - b


a, b = 2, 1
swap(a, b)
print(a, b)

a = a ^ b
b = a ^ b
a = a ^ b
print(a, b)


# anonymous functions
square = lambda x: x * x
log2 = lambda n: 0 if n <= 1 else 1 + log2(n//2)

print(square(4))
print(log2(8))
print(log2(7))
