from datetime import datetime

ls = ['Hello', 'World', 1, 2, datetime.now()]
ls.append(3)
ls.insert(0, lambda b, ex: b ** ex)

print(ls[0](4, 2))

ls.extend([2.3, .5, .6])
print(ls)

ls.remove(0.6)
print(ls)

# pop() removes and returns the last element from the list
print(f'pop(): {ls.pop()}')
print(f'pop(0): {ls.pop(0)}')

# slicing
print(ls)
print(ls[-4: -2])
print(ls[::-1])

# range function
for i in range(1, 11, 2):
    print(i)

# list comprehensions
even_nums = [2*x for x in range(1, 6)]
print(even_nums)
even_square = [x ** 2 for x in range(1, 10) if x % 2 == 0]
print(even_square)

# nested list comprehension
matrix = [[j for j in range(5)] for i in range(5)]
print(matrix)
'''
Build the matrix [[1, 2, 3], [4, 5, 6], [7, 8, 9]] using list comprehension 
'''

# flatten the matrix

flat = [el for row in matrix for el in row]
print(flat)
