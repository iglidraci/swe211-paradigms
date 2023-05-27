from numbers import successor, zero, print_nr, one, two, three
from conditionals import TRUE, FALSE, NOT

# Φ ≡ (λpz.z(S(pT))(pT))

PHI = lambda p: lambda z: z(successor(p(TRUE)))(p(TRUE))

# P ≡ (λn.nΦ(λz.z00)F)
predecessor = lambda n: n(PHI)(lambda z: z(zero)(zero))(FALSE)


Y = lambda y: (lambda x: y(lambda z: x(x)(z)))(lambda x: y(lambda z: x(x)(z)))


# Z ≡ λx.xF¬F

Z = lambda x: x(FALSE)(NOT)(FALSE)

# R ≡ (λrn.Zn0(nS(r(Pn))))
R = lambda r: lambda n: lambda m: Z(n)(zero)(n(successor)(r(predecessor(n))))(m)

if __name__ == '__main__':
    print_nr(predecessor(one))
    print_nr(predecessor(two))
    print_nr(predecessor(three))
    print_nr(predecessor(successor(three)))
    print(Z(zero) == TRUE)
    five = successor(successor(three))
    print_nr(Y(R)(five))
