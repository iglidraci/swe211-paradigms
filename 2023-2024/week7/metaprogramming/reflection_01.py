import inspect
from types import MethodType


class Student:
    def __init__(self, name, program):
        self.name = name
        self.program = program

    def study(self):
        print(f'{self.name} in {self.program} is studying ...')


def sleep(self, time):
    print(f'{self.name} sleeping for {time} minutes')


if __name__ == '__main__':
    s = Student("Foo", "SWE")
    print(dir(s))  # introspect attributes and methods
    print(getattr(s, 'program'))
    setattr(s, 'program', 'CEN')
    s.study()
    has_gpa = hasattr(s, 'gpa')
    print(f'has gpa? {has_gpa}')
    print(inspect.ismethod(s.study))
    print(inspect.isfunction(sleep))
    print(inspect.getfullargspec(sleep).args)
    s.gpa = 4.0  # dynamically creating an attribute
    s.sleep = MethodType(sleep, s)
    s.sleep(2)
