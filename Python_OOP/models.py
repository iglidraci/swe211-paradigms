import uuid


class Person:
    def __init__(self, personal_number, name):
        self.personal_number = personal_number
        self.name = name

    # static methods know nothing about the class state
    @staticmethod
    def generate_random_id():
        # generates random id using mac address and time component
        return uuid.uuid1()

    @staticmethod
    def is_adult(age):
        return age > 21

    def __str__(self):
        return f'{self.name} with personal number {self.personal_number}'


class Student(Person):
    # class attributes
    university = "Epoka"

    def __init__(self, personal_number: str, name: str, program: str, age: int):
        #  forget to invoke the __init__() of the parent class
        super().__init__(personal_number, name)
        self.program = program
        self.age = age

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, a):
        self.__age = max(a, 18)

    def introduce(self):
        print(f"Hello, I'm {self.name} and I study {self.program}")

    def __del__(self):
        print("Destructor called, student deleted")
