I = lambda x: x

II = I(I)

if __name__ == '__main__':
    assert I == II
