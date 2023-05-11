TRUE = lambda x: lambda y: x
FALSE = lambda x: lambda y: y

"""
The AND function of two arguments can be defined as
∧ ≡ λxy.xy(λuv.v) ≡ λxy.xyF
"""
AND = lambda x: lambda y: x(y)(FALSE)

"""
The OR function of two arguments can be defined as
∨ ≡ λxy.x(λuv.u)y ≡ λxy.xTy
"""
OR = lambda x: lambda y: x(TRUE)(y)

"""
Negation of one argument can be defined as
¬ ≡ λx.x(λuv.v)(λab.a) ≡ λx.xFT
"""
NOT = lambda x: x(FALSE)(TRUE)


if __name__ == '__main__':
    assert AND(TRUE)(FALSE) is FALSE
    assert AND(TRUE)(TRUE) is TRUE
    assert AND(FALSE)(TRUE) is FALSE
    assert AND(FALSE)(FALSE) is FALSE

    assert OR(TRUE)(TRUE) is TRUE
    assert OR(TRUE)(FALSE) is TRUE
    assert OR(FALSE)(TRUE) is TRUE
    assert OR(FALSE)(FALSE) is FALSE

    assert NOT(TRUE) is FALSE
    assert NOT(FALSE) is TRUE
