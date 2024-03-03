# strings are immutable

course = "Programming Language Paradigms"
print(f'First char: {course[0]}, last char: {course[-1]}')

'''
lower(), upper(), title(), capitalize(), endswith(), startswith()
count() returns the number of occurrences of a substring in the string
index(), isalpha(), isdigit()
'''

# slicing
print(course[3: 7])
print(course[3:-1])
print(course[:-1])
print(course[course.index('Pa'):])




def is_palindrome(string):
    """
    check if the given string is a palindrome
    """
    pass


print(is_palindrome("aibohphobia"))
