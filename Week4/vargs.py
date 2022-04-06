def qux(a, b, *args, **kwargs):
    print(f"a = {a}")
    print(f"b = {b}")
    print(f"args = {args}")
    print(f"kwargs = {kwargs}")


if __name__ == '__main__':
    qux(1, 2, "a", "b", "c", id=1, name="Qux")
