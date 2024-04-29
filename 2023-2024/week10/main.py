from numbers import *
from conditionals import *

increment = lambda x: x + 1  # illegal in terms of lambda calculus but nevertheless helps visualize things
print_nr = lambda x: print(x(increment)(0))  # illegal in lambda calculus but just for simplicity
LAMBDAS = lambda x: 'λ' + x
OMEGA = lambda x: x(x)

if __name__ == '__main__':
    print(TWO(increment)(0))
    print(THREE(increment)(0))
    print(FOUR(increment)(0))
    print_nr(FOUR)
    print_nr(SIX)
    print(THREE(LAMBDAS)(''))
    print(THREE(THREE)(LAMBDAS)(''))
    print_nr(THREE(THREE))
    print_nr(FOUR(FOUR))
    print_nr(TWO(THREE)(TWO))
    # OMEGA(OMEGA)    # lambda expression that diverges
    print_nr(MULTIPLY(FOUR)(THREE))
    TEN = ADD(MULTIPLY(THREE)(THREE))(ONE)
    print_nr(TEN)
    HUNDRED = MULTIPLY(TEN)(TEN)
    print_nr(HUNDRED)
    assert AND(TRUE)(TRUE) is TRUE
    assert AND(TRUE)(FALSE) is FALSE
    assert AND(FALSE)(TRUE) is FALSE
    assert AND(FALSE)(FALSE) is FALSE
    assert NOT(TRUE) is FALSE
    assert NOT(FALSE) is TRUE
    assert IS_ZERO(ZERO) is TRUE
    assert IS_ZERO(ONE) is FALSE
