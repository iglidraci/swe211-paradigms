"""
Metaclasses are classes that can be created separately with certain features that can alter the behavior of other classes 
or can help in dynamically manufacturing new classes. 
The base class of all metaclasses is the type class and the object or instance of a metaclass will be a class.
"""


class PascalCaseAttributesMeta(type):
    def __new__(cls, classname, baseclasses, attributes):
        # The __new__ method is responsible for creating the class object
        pascal_case = {
            ''.join(piece.title() for piece in key.split('_')): value for key, value in attributes.items()
        }
        return super().__new__(cls, classname, baseclasses, pascal_case)


class Foo(metaclass=PascalCaseAttributesMeta):
    first_name = 'aa'
    last_name = 'bb'


# only one instance throughout the lifetime of program
class SingletonMeta(type):
    _instance = None

    def __call__(cls, *args, **kwargs):
        # The __call__ method is called when an instance of the class is created
        if cls._instance is None:
            cls._instance = super().__call__(*args, **kwargs)
        return cls._instance


class Database(metaclass=SingletonMeta):
    pass


class PositiveIntAttributesOnlyMeta(type):
    def __new__(cls, name, bases, attributes):
        for key, value in attributes.items():
            if not key.startswith('_'):
                if not isinstance(value, int):
                    raise TypeError(f'Attribute {key} must be integer')
                if value < 0:
                    raise TypeError(f'Attribute {key} must be non-negative')
        return super().__new__(cls, name, bases, attributes)


if __name__ == '__main__':
    f = Foo()
    print(f.FirstName)
    db1 = Database()
    db2 = Database()
    print(db1 == db2)
