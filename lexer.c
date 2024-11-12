#include "lexer.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>

lexer *new_lexer(FILE *fptr)
{
    lexer *l = (lexer *)malloc(sizeof(lexer));
    if (l == NULL)
    {
        fprintf(stderr, "out of memory\n");
        exit(0);
    }

    l->fptr = fptr;
    l->position = 0;
    l->read_position = 0;

    read_char(l);
}

void read_char(lexer *l)
{
    l->ch = fgetc(l->fptr);
    l->position = l->read_position;
    l->read_position++;
}