from abc import ABC, abstractmethod


class Class1:
    def foo(self):
        print("foo from Class1")


class Class2(Class1):
    def foo(self):
        print("foo from Class2")

    def bar(self):
        print("bar")


class Class3(Class1):
    def foo(self):
        print("foo from Class3")

    def qux(self):
        print("qux")


class Class4(Class2, Class3):
    def foo(self):
        """by default, it will use the implementation of Class2"""
        Class3.foo(self)


class Edible(ABC):

    @abstractmethod
    def how_to_eat(self):
        pass


class Animal(ABC):

    @abstractmethod
    def walk(self):
        pass

    def breathe(self):
        print("braething ...")


class Tiger(Animal):
    def walk(self):
        print("Tigers walk on four legs")


class WeightException(BaseException):
    pass


class Chicken(Animal, Edible):

    def __init__(self, weight=1):
        self.weight = weight

    @property
    def weight(self):
        return self.__weight

    @weight.setter
    def weight(self, w):
        if w <= 0:
            raise WeightException("Chicken weight can only be positive number")
        self.__weight = w

    def walk(self):
        print("Chickens walk on two legs")

    def how_to_eat(self):
        print("Fry it!")

    def __add__(self, other):
        return self.weight + other.weight