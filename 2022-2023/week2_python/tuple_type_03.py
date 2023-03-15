# tuples are immutable

t1 = ('id', 'name', 'age')
t2 = (1, 'foo', 77)

a = ('Hello',)
b = ('Hello')   # a string, not a tuple
# unpacking a tuple
a1, a2, a3 = ("apple", "banana", "cherry")
print(a1, a2, a3)