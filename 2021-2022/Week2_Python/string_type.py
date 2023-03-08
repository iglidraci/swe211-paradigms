course = "Programming Paradigms"
print(f"First char: {course[0]}, last char: {course[-1]}")

# slicing
print(course[3:-1])
print(course[course.index("Pa"):])

# Strings are immutable, you can't change characters from a string
escaped = "National \"traitor\""
print(escaped)
raw = r"National \"traitor\""
print(raw)

# lower(), upper(), title(), capitalize(), endswith(), startswith()
# count() Returns the number of occurrences of a substring in the string.
# index(), isalpha(), isdigit()

print(course.count("P"))
prolog = "Logic Programming with Prolog"
print(prolog.index("Pro"))

# todo reverse a string
# todo check if string is palindrome


def is_palindrome(string: str) -> bool:
    pass


print(is_palindrome("aibohphobia"))
