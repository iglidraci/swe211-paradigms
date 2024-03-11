def longest_unique_substring(s):
    left = right = longest = 0
    seen_chars = []
    while right != len(s):
        if not s[right] in seen_chars:
            seen_chars.append(s[right])
            right += 1
        else:
            seen_chars.remove(s[left])
            left += 1
        longest  = max(longest, len(seen_chars))
    return longest


if __name__ == '__main__':
    print(longest_unique_substring('pwwkew'))

