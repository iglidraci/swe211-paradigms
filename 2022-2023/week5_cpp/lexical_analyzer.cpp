#include <iostream>

using namespace std;
/* Global declarations */ /* Variables */
int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int nextToken;
FILE *in_fp;

/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();


/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

int main() {
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("expression", "r")) == NULL)
        cout << "ERROR - cannot open expression \n";
    else {
        getChar();
        do {
            lex();
        } while (nextToken != EOF);

    }
}

/* lookup - a function to lookup operators and parentheses and return the token */
int lookup(char ch) {
    addChar();
    switch (ch) { case '(':
            nextToken = LEFT_PAREN;
            break;
        case ')':
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            nextToken = ADD_OP;
            break;
        case '-':
            nextToken = SUB_OP;
            break;
        case '*':
            nextToken = MULT_OP;
            break;
        case '/':
            nextToken = DIV_OP;
            break;
        case '=':
            nextToken = ASSIGN_OP;
            break;
        default:
            nextToken = EOF;
            break;
    }
    return nextToken;
}

/* addChar - a function to add nextChar to lexeme */
void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    }
    else
        cout << "Error - lexeme is too long" << endl;
}

/* getChar - a function to get the next character of input and determine its character class
 * When called, getChar gets the next character of input from the input program and puts
 * it in the global variable nextChar.
 * getChar also must determine the character class of the input character and put it in the global variable charClass
 * */
void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else charClass = UNKNOWN;
    }
    else
        charClass = EOF;
}


/* getNonBlank - a function to call getChar until it returns a non-whitespace character */
void getNonBlank() {
    while (isspace(nextChar))
        getChar();
}

/* lex - a simple lexical analyzer for arithmetic expressions */
int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        case LETTER: /* Parse identifiers */
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;
        case DIGIT: /* Parse integer literals */
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
        case UNKNOWN: /* Parentheses and operators */
            lookup(nextChar);
            getChar();
            break;
        case EOF: /* EOF */
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    } /* End of switch */
    cout << "Next token is: " << nextToken << ", Next lexeme is " << lexeme << endl;
    return nextToken;
}  /* End of function lex */
