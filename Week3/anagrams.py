def is_anagram(str1: str, str2: str) -> bool:
    if len(str1) != len(str2): return False
    map1, map2 = {}, {}
    for i in range(len(str1)):
        map1[str1[i]] = map1.get(str1[i], 0) + 1
        map2[str2[i]] = map2.get(str2[i], 0) + 1
    for char in map1.keys():
        if map1[char] != map2.get(char, 0): return False
    return True


if __name__ == '__main__':
    s1, s2 = input("Enter two strings to check whether they are anagrams or not: ").split(' ')
    print("yes" if is_anagram(s1, s2) else "no")
