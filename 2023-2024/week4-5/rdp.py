import sys
from lex import lex, get_char, open_file, ADD_OP, SUB_OP, MULT_OP, DIV_OP, IDENT, INT_LIT, FLOAT_LIT, LEFT_PAREN, RIGHT_PAREN, EOF, WHILE, \
    LEFT_CURLY_BRACKET, RIGHT_CURLY_BRACKET, COMMENT

next_token = None
next_lexeme = None

def error():
    print('Parser failed')
    exit(1)


def program():
    global next_lexeme, next_token
    print('Enter <program>')
    stmt_list()
    print('Exit <program>')

def _while():
    global next_lexeme, next_token
    print('Enter <while>')
    next_lexeme, next_token = lex()
    if next_token == LEFT_PAREN:
        next_lexeme, next_token = lex()
        expr()
        if next_token == RIGHT_PAREN:
            next_lexeme, next_token = lex()
            if next_token == LEFT_CURLY_BRACKET:
                next_lexeme, next_token = lex()
                while True:
                    if next_token == RIGHT_CURLY_BRACKET:
                        next_lexeme, next_token = lex()
                        break
                    elif next_token == COMMENT:
                        skip_comment()
                    elif next_token == WHILE:
                        _while()
                    else:
                        expr()       
                # next_lexeme, next_token = lex()
                # expr()
                # if next_token == RIGHT_CURLY_BRACKET:
                #     next_lexeme, next_token = lex()
                # else:
                #     error()
            else:
                error()
        else:
            error()
    else:
        error()

def stmt_list():
    global next_lexeme, next_token
    print('Enter <stmt_list>')
    while True:
        if next_token == COMMENT:
            skip_comment()
        elif next_token == WHILE:
            _while()
        else:
            expr()
        if next_token == EOF:
            break
    print('Exit <stmt_list>')

def factor():
    global next_lexeme, next_token
    print('Enter <factor>')
    if next_token in (IDENT, INT_LIT, FLOAT_LIT):
        next_lexeme, next_token = lex()
    else:
        if next_token == LEFT_PAREN:
            next_lexeme, next_token = lex()
            expr()
            if next_token == RIGHT_PAREN:
                next_lexeme, next_token = lex()
            else:
                error()
        else:
            error()
    print('Exit <factor>')


def term():
    global next_lexeme, next_token
    print('Enter <term>')
    factor()
    while next_token in (MULT_OP, DIV_OP):
        next_lexeme, next_token = lex()
        factor()
    print('Exit <term>')


def expr():
    global next_token, next_lexeme
    print('Enter <expr>')
    # parse the first term
    term()
    while next_token in (ADD_OP, SUB_OP):
        next_lexeme, next_token = lex()
        term()
    print('Exit <expr>')


def skip_comment():
    global next_token, next_lexeme
    while next_token == COMMENT:
        next_lexeme, next_token = lex()


if __name__ == '__main__':
    open_file('program2.txt')
    get_char()
    next_lexeme, next_token = lex()
    program()
