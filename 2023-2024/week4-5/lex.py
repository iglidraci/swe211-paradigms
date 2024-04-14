import sys
'''
A lexical analyzer for simple arithmetic expressions
To run this script: python lex.py filepath
'''

input_file = None
char_class = None
next_char = None

# character classes
LETTER = 0
DIGIT = 1
SLASH = 2
STAR  = 3
UNKNOWN = 99

# tokens
INT_LIT = 'int literal'
FLOAT_LIT = 'float literal'
IDENT = 'identifier'
ASSIGN_OP = 'assign operator'
ADD_OP = 'add operator'
SUB_OP = 'subtract operator'
MULT_OP = 'multiply operator'
DIV_OP = 'divide operator'
LEFT_PAREN = 'left parentheses'
RIGHT_PAREN = 'right parentheses'
COMMENT = 'comment'
WHILE = 'while'
LEFT_CURLY_BRACKET = 'left curly bracket'
RIGHT_CURLY_BRACKET = 'right curly bracket'
EOF = 'EOF'

# lookup
LOOKUP_TABLE = {
    '(': LEFT_PAREN,
    ')': RIGHT_PAREN,
    '+': ADD_OP,
    '-': SUB_OP,
    '*': MULT_OP,
    '{': LEFT_CURLY_BRACKET,
    '}': RIGHT_CURLY_BRACKET
}

KEYWORDS = {'while': WHILE}


def get_char():
    global next_char
    global char_class
    next_char = input_file.read(1)
    if next_char != '':
        if next_char.isalpha():
            char_class = LETTER
        elif next_char.isdigit():
            char_class = DIGIT
        elif next_char == '/':
            char_class = SLASH
        elif next_char == '*':
            char_class = STAR
        else:
            char_class = UNKNOWN
    else:
        char_class = EOF
    


def lex():
    next_token = None
    lexeme = ''
    # get next non blank
    while next_char.isspace():
        get_char()
    # parse identifiers or keywords
    if char_class == LETTER:
        lexeme += next_char # add char
        get_char()
        while char_class == LETTER or char_class == DIGIT:
            lexeme += next_char
            get_char()
        next_token = KEYWORDS.get(lexeme, IDENT)
    elif char_class == DIGIT:
        lexeme += next_char
        get_char()
        while char_class == DIGIT:
            lexeme += next_char
            get_char()
        if next_char == '.':
            lexeme += next_char
            get_char()
            while char_class == DIGIT:
                lexeme += next_char
                get_char()
            if next_char in ('F', 'f'):
                lexeme += next_char
                get_char()
            next_token = FLOAT_LIT
        else:
            next_token = INT_LIT
    elif char_class == SLASH:
        lexeme += next_char
        get_char()
        if char_class == STAR: # parse comment
            lexeme += next_char
            get_char()
            comment_end = False
            while not comment_end:
                lexeme += next_char
                get_char()
                if char_class == STAR:
                    lexeme += next_char
                    get_char()
                    if char_class == SLASH:
                        lexeme += next_char
                        get_char()
                        next_token = COMMENT
                        comment_end = True
            lexeme += next_char
            get_char()
        else:
            next_token = DIV_OP
    elif char_class == UNKNOWN or char_class == STAR:
        next_token = LOOKUP_TABLE.get(next_char, EOF)
        lexeme += next_char
        get_char()
    elif char_class == EOF:
        next_token = EOF
        lexeme = EOF
    return (lexeme, next_token)


def open_file(path):
    global input_file
    input_file = open(path, 'r')


if __name__ == '__main__':
    open_file(sys.argv[1])
    get_char()
    while True: # do ... while next token is EOF
        lexeme, token = lex()
        print(f'Next token is: {token}, Next lexeme is {lexeme}')
        if token == EOF:
            break