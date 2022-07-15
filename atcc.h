#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tokenize.c

// kind of token
typedef enum {
    TK_RESERVED,            // symbol
    TK_NUM,                 // integer token
    TK_EOF,                 // a token represented input ending
} TokenKind;

typedef struct Token Token;

// type of token
struct Token {
    TokenKind kind;         // type of token
    Token *next;            // next input token
    int val;                // the value if kind is TK_NUM
    char *str;              // token string    
};

// a token we notice now
Token *token;

void error(char *fmt, ...);
bool consume(char op);
int expected_number();
bool at_eof();
Token *new_token(TokenKind kind, Token *cur, char *str);
Token *tokenize(char *p);
