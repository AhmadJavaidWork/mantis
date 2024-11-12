#include "token.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *lookup_keyword(char *literal)
{
    if (strcmp("fn", literal) == 0)
    {
        return FUNCTION;
    }
    else if (strcmp("let", literal) == 0)
    {
        return LET;
    }
    else if (strcmp("return", literal) == 0)
    {
        return RETURN;
    }
    else if (strcmp("true", literal) == 0)
    {
        return TRUE;
    }
    else if (strcmp("false", literal) == 0)
    {
        return FALSE;
    }
    else if (strcmp("if", literal) == 0)
    {
        return IF;
    }
    else if (strcmp("else", literal) == 0)
    {
        return ELSE;
    }
    else
    {
        return IDENT;
    }
}

void free_token(token t)
{
    free(t.literal);
    free(t.token_type);
}