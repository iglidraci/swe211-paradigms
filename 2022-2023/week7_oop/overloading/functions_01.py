from math import sqrt
from typing import List


class Order:
    def __init__(self, items: List[str], customer: str):
        self.items = items
        self.customer = customer

    def __len__(self):
        """
        We can use the len() built-in function to obtain the length of the cart
        If __len__() were to return anything but an integer, it will raise TypeError
        """
        return len(self.items)

    def __bool__(self):
        """
        We can use the built-int function bool() to obtain the truthy value of the object
        """
        return len(self) > 0


class Vector:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y

    def __abs__(self):
        """
        Makes more sense to say absolute value of vector than to create a method
        to return the magnitude of a vector
        """
        return sqrt(self.x**2 + self.y**2)

    def __str__(self):
        return f'{self.x}i+{self.y}j'


if __name__ == '__main__':
    order = Order(['apples', 'bananas', 'kiwis'], 'Foo')
    print(len(order))
    print(bool(order))
    if order:
        print('processing the order')
    v = Vector(3, 4)
    print(abs(v))
    print(v)
