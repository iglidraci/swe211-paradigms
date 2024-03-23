def DFA(machine, string) -> bool:
    Q, q0, sigma, transition_table, F = machine # machine tuple
    for char in string:
        if char not in sigma:
            raise ValueError(f"{char} not part of the alphabet")
        if (q0, char) not in transition_table:
            return False
        q0 = transition_table[(q0, char)]
        if q0 not in Q:
            raise ValueError('state {q0} not in set of states')
    return q0 in F


if __name__ == '__main__':
    pass
