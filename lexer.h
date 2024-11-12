#include <stdio.h>

typedef struct lexer
{
    char ch;
    FILE *fptr;
    int position;
    int read_position;
} lexer;

struct lexer *new_lexer(FILE *fptr);
void read_char(struct lexer *l);