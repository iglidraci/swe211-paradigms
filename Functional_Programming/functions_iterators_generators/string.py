def remove(text: str, chars: str) -> str:
    '''
    This function will recursively remove each of the characters from chars
    '''
    if chars:
        return remove(text.replace(chars[0], ""), chars[1:])
    return text

print(remove("Hello $$ World ??", "$?"))