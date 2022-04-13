from abc import ABC, abstractmethod


class Stack(ABC):
    @abstractmethod
    def pop(self):
        pass

    @abstractmethod
    def push(self, value):
        pass

    @abstractmethod
    def peek(self):
        pass

    @abstractmethod
    def is_empty(self):
        pass

    @abstractmethod
    def size(self):
        pass


class ArrayStack(Stack):
    def __init__(self):
        self.__array = []

    def pop(self):
        if self.is_empty(): return None
        return self.__array.pop()

    def push(self, value):
        self.__array.append(value)

    def peek(self):
        if self.is_empty(): return None
        return self.__array[-1]

    def is_empty(self):
        return self.size() == 0

    def size(self):
        return len(self.__array)

    def __str__(self):
        return str(self.__array)