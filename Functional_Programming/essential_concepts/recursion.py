'''
coprime mean that two numbers have only one as their common
factor
The numbers 2 and 3, for example, are coprime. The numbers 6 and 9, however, are
not coprime because they have three as a common factor
'''
from math import sqrt


# not any version can terminate early if a True value is found
# : it's not a pure example of stateless functional programming
prime = lambda n: not any (n % x == 0 for x in range(2, int(sqrt(n)) + 1))

assert prime(3)
assert prime(5)
assert not prime(15)

'''
let's define it recursively

coprime(n, [a, b[) = {
    True                                    if a = b
    (n mod a) != 0 ^ coprime(n, [a+1, b[)   if a < b
}
Explanation:

If the range is empty, a==b, we have evaluated something like 
coprime(131073, [363, 363[) and the return should be True
If the range is not empty, we have evaluated something like
coprime(131073, [2, 363[) which will decompose into coprime(131073, [3, 363[)
'''

def is_prime(n: int) -> bool:
    def _is_prime(k: int, a: int) -> bool:
        if k < a**2: return True # base case
        if k % a == 0: return False
        return _is_prime(k, a+1) # tail recursion
    if n <= 1: return False # number 1 is not prime
    if n % 2 == 0: return False
    return _is_prime(n, 3)


assert not is_prime(131073)
assert is_prime(7)