ZERO = lambda s: lambda z: z
ONE = lambda s: lambda z: s(z)
TWO = lambda s: lambda z: s(s(z))

SUCCESSOR = lambda w: lambda y: lambda x: y(w(y)(x))

THREE = SUCCESSOR(TWO)
FOUR = SUCCESSOR(THREE)
SIX = SUCCESSOR(SUCCESSOR(FOUR))

ADD = lambda x: lambda y: y(SUCCESSOR)(x)

MULTIPLY = lambda x: lambda y: lambda z: x(y(z))