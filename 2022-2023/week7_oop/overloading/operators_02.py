from typing import Any

from overloading.functions_01 import Order


class AdvOrder(Order):
    def __add__(self, other: Any):
        if isinstance(other, str):
            new_order = self.items.copy()
            new_order.append(other)
            return AdvOrder(new_order, self.customer)
        else:
            raise NotImplemented("Can only append instances of str")

    def __iadd__(self, other: Any):
        """Shortcut for += operator"""
        if isinstance(other, str):
            self.items.append(other)
            return self
        else:
            raise NotImplemented("Can only append instances of str")

    def __getitem__(self, key):
        """The [] operator is called the indexing operator"""
        return self.items[key]

    def __setitem__(self, key, value):
        self.items[key] = value

    def __radd__(self, other: Any):
        """Reverse special methods. Adding to the front of the list"""
        if isinstance(other, str):
            new_order = self.items.copy()
            new_order.insert(0, other)
            return AdvOrder(new_order, self.customer)
        else:
            raise NotImplemented("Can only append instances of str")


if __name__ == '__main__':
    order = AdvOrder(['apples', 'bananas', 'kiwis'], 'Foo')
    new_order = order + "dates"
    print(new_order.items)
    print(order.items)
    new_order += 'oranges'
    print(new_order.items)
    print(new_order[3])
    print(new_order[2:])
    new_order[1] = 'strawberry'
    new_order = 'watermelon' + new_order
    print(new_order.items)
