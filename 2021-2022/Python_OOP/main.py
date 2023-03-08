from inheritance import Class4, Chicken
from models import Student, Person
from stack import ArrayStack


def main():
    std1 = Student(Person.generate_random_id(), "Bob", "SWE", 20)
    std2 = Student(Person.generate_random_id(), "Alice", "CEN", 17)
    std1.introduce()
    std2.introduce()
    print(std2.age)
    print(Student.university)
    cls4 = Class4()
    cls4.foo()
    chicken = Chicken(1)
    chicken2 = Chicken(4)
    print(chicken + chicken2)
    chicken.how_to_eat()
    stack = ArrayStack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    assert stack.pop() == 3
    print(stack)
    print("End of the main()")


if __name__ == '__main__':
    main()
