h_map = {
    'id': 1,
    'name': 'Foo',
    'grades': {
        'linear algebra': 'AA',
        'english': 'AA'
    }
}

# insert new K/V
h_map['program'] = 'SWE'
print(h_map)

# iterate through keys

for key in h_map.keys():
    print(f"Key: {key}, Value: {h_map[key]}")

for val in h_map.values():
    print(f"Value: {val}")

# Pop() method is used to return and delete the value of the key specified
name = h_map.pop('name')
print(name, h_map, sep='->')


# calculate fibonacci of 100 using recursion
# try using a dictionary
def fib(n):
    pass


print(fib(100))
