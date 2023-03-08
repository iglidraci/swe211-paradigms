from datetime import datetime

ls = ['Hello', 'World', 1, 2, datetime.now()]
ls.append(3)
ls.insert(0, lambda b, ex: b ** ex)

print(ls[0](4, 2))

ls.extend([2.3, .5, .6])
print(ls)

power = ls[0]

if power in ls:
    ls.remove(power)
    print(ls)

# pop() removes and returns an element from the list, by default the last element, pop(0) for example

print(f"pop(0): {ls.pop(0)}")
print(f"pop(): {ls.pop()}")
print(ls)

# slicing
print(ls[-4: -2])

# list comprehensions

even_square = [x ** 2 for x in range(1, 20) if x % 2 == 0]
print(even_square)

# Nested list comprehension
matrix = [[j for j in range(5)] for i in range(5)]
print(matrix)

# flatten the matrix now
flat = [el for row in matrix for el in row]
print(flat)

flat.reverse()
print(flat)

print(f"Count of 0: {flat.count(0)}")


# todo reverse a list using recursion
def reverse(array: []):
    pass


reverse(flat)
print(flat)
