# A Python lambda is a pure function
# Because lambdas can't have assignment statements, they're always pure functions 
# and suitable for functional programming

# In mathematics, a Mersenne prime is a prime number that is one less than a power of two
mersenne = lambda x: 2**x - 1
print(mersenne(4))

# high-order functions are functions that accept a function as an argument or return a function as a value
# first-class functions are functions that are treated as variables

years = [(2000, 29.87), (2001, 30.12), (2002, 30.6), (2003, 30.66),(2004, 31.33), 
        (2005, 32.62), (2006, 32.73), (2007, 33.5),
        (2008, 32.84), (2009, 33.02), (2010, 32.92)]

# the default behavior is the compare the element at index 0 of the tuple
print(max(years))
print(max(years, key=lambda x: x[1]))