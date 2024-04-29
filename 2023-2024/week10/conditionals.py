TRUE = lambda x: lambda y: x
FALSE = lambda x: lambda y: y

AND = lambda x: lambda y: x(y)(FALSE)

OR = lambda x: lambda y: x(TRUE)(y)

NOT = lambda x: x(FALSE)(TRUE)

# function which is true if a number is zero and false otherwise
IS_ZERO = lambda x: x(FALSE)(NOT)(FALSE)
