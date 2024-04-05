class A(object):

    def display(self):
        print(f" From class A")


class B(A):

    def display(self):
        print(f" From class B")


class C(A):

    def display(self):
        print(f" From class C")


class D(C, B):

    def display(self):
        print(f" From class D")


class E(B, C):

    def display(self):
        print(f" From class E")


# class F(D,E):
#
#     def display(self):
#         print(f" From class F")


if __name__ == '__main__':
    print(D.__mro__)
    print(E.__mro__)