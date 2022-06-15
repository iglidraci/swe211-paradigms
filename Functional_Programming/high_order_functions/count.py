'''
https://crocoder.dev/blog/map-filter-reduce-exercises/

Count elements in an array of arrays
Count the occurrences of distinct elements in the given 2D array.
The given input is an array, the elements of which are arrays of strings.
The result is a dictionary whose keys are the values from the arrays and 
their value is the number of their occurrences.

Example
Input: [
    ['a', 'b', 'c'],
    ['c', 'd', 'f'],
    ['d', 'f', 'g'],
  ]
Output: 
{
    a: 1,
    b: 1,
    c: 2,
    d: 2,
    f: 2,
    g: 1,
  }
'''

from functools import reduce
from typing import Any

from funcs import my_reduce


flatten = lambda matrix: (i for array in matrix for i in array)


def count(frequencies: dict, element: Any) -> dict:
    if element in frequencies:
        return {
            **frequencies,
            element: frequencies[element] + 1
        }
    else:
        return {
            **frequencies,
            element: 1
        }


inp = [
    ['a', 'b', 'c'],
    ['c', 'd', 'f'],
    ['d', 'f', 'g'],
]

print(reduce(count, flatten(inp), {}))
print(my_reduce(flatten(inp), count, {}))
