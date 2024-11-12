#include <stdio.h>
#include "token.h"
#include <stdbool.h>

typedef struct lexer
{
    char ch;
    FILE *fptr;
    int position;
    int read_position;
} lexer;

lexer *new_lexer(FILE *fptr);

void read_char(lexer *l);

token next_token(lexer *l);

void skip_white_spaces(lexer *l);

int peek_char_is(lexer *l, char c);

int is_digit(int c);

int is_letter(int c);

char *read_identifier(lexer *l, int (*f)(int c));

token new_token(char *t, char *l);

void free_lexer(lexer *l);