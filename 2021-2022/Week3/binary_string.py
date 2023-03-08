def find_kth_bit(n: int, k: int) -> str:
    s = find_s(n)
    print(s)
    return s[k-1]


def find_s(n):
    if n == 1:
        return '1'
    prev = find_s(n-1)
    return prev + '0' + ''.join((list(transform(prev))))


def transform(s):
    return ''.join(list(map(lambda x: '0' if x == '1' else '1', reversed(s))))


if __name__ == '__main__':
    print(find_kth_bit(4, 11))
