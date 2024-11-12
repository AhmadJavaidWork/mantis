#include "string.h"
#include "stdlib.h"
#include "lexer.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: mantis path/to/file.mantis\n");
        return 1;
    }

    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "file not found\n");
        return 1;
    }

    lexer *l = new_lexer(fptr);
    free_lexer(l);
    fclose(fptr);

    return 0;
}