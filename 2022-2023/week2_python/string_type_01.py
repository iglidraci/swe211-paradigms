course = "Programming Language Paradigms"
print(f'First char: {course[0]}, last char: {course[-1]}')

# slicing
print(course[3: 7])
print(course[3:-1])
print(course[:-1])
print(course[course.index('Pa'):])

# strings are immutable
escaped = 'O\'Reilly'
r_str = r'O\'Reilly'
print(escaped, r_str)

'''
lower(), upper(), title(), capitalize(), endswith(), startswith()
count() returns the number of occurrences of a substring in the string
index(), isalpha(), isdigit()
'''


def is_palindrome(string):
    """
    check if the given string as a palindrome
    """
    pass


print(is_palindrome("aibohphobia"))
