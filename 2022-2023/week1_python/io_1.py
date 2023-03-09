import math
import sys

ASK_FOR_INPUT = False

if ASK_FOR_INPUT:
    name = input("Enter your name\n->")
    age = input("enter your age\n->")
else:
    name = 'Foo'
    age = '20'

print("your name is {} and your age is {}".format(name, age))
print("type of name: %s, type of age: %s" % (type(name), type(age)))
age = int(age)
print(f"type of age is now {type(age)}")
print("2 decimal places PI -> %.2f" % math.pi)

# taking multiple inputs
# this is called unpacking
x, y, z = input("Enter three numbers separated by space: ").split(" ") if ASK_FOR_INPUT else [1, 2, 3]
print(f"x: {x}, y: {y} and z: {z}")

# print(value(s), sep= ‘ ‘, end = ‘\n’, file=file)
print("hello", "world", sep=', ', file=open('aa.txt', 'w'))
