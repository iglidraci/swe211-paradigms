def product(*args):
    res = 1
    for nr in args:
        res *= nr
    return res


def qux(a, b, *args, **kwargs):
    print(f"a = {a}")
    print(f"b = {b}")
    print(f"args = {args}")
    print(f"kwargs = {kwargs}")


if __name__ == '__main__':
    print(product(1, 2, 3))
    print(product(*[1, 2, 3]))
    qux(1, 2, 3, 'a', 'b', id=1, name='Foo')
    letters = ['a', 'b']
    kw = {'id': 1, 'name': 'Foo'}
    qux(1, 2, *letters, **kw)
    qux(1, 2, kw)