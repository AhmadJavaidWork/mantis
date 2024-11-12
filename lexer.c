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

token next_token(lexer *l)
{
    token tok;
    char *token_type;
    char *literal;

    skip_white_spaces(l);

    switch (l->ch)
    {
    case 0:
        tok = new_token("EOF", "EOF");
        break;

    case -1:
        tok = new_token("EOF", "EOF");
        break;

    case '+':
        tok = new_token(PLUS, "+");
        break;

    case '-':
        tok = new_token(MINUS, "-");
        break;

    case '*':
        tok = new_token(ASTERISK, "*");
        break;

    case '/':
        tok = new_token(SLASH, "/");
        break;

    case '<':
        tok = new_token(LT, "<");
        break;

    case '>':
        tok = new_token(GT, ">");
        break;

    case '!':
        if (peek_char_is(l, '='))
        {
            read_char(l);
            tok = new_token(NOT_EQ, "!=");
        }
        else
        {
            tok = new_token(BANG, "!");
        }
        break;

    case '=':
        if (peek_char_is(l, '='))
        {
            read_char(l);
            tok = new_token(EQ, "==");
        }
        else
        {
            tok = new_token(ASSIGN, "=");
        }
        break;

    case ',':
        tok = new_token(COMMA, ",");
        break;

    case ':':
        tok = new_token(COLON, ":");
        break;

    case ';':
        tok = new_token(SEMI_COLON, ";");
        break;

    case '(':
        tok = new_token(LPAREN, "(");
        break;

    case ')':
        tok = new_token(RPAREN, ")");
        break;

    case '{':
        tok = new_token(LBRACE, "{");
        break;

    case '}':
        tok = new_token(RBRACE, "}");
        break;

    case '[':
        tok = new_token(LBRACKET, "[");
        break;

    case ']':
        tok = new_token(RBRACKET, "]");
        break;

    default:
        if (is_letter(l->ch))
        {
            char *literal = read_identifier(l, is_letter);
            char *token_type = lookup_keyword(literal);
            tok = new_token(token_type, literal);
            free(literal);
            return tok;
        }
        else if (is_digit(l->ch))
        {
            char *literal = read_identifier(l, is_digit);
            tok = new_token(INT, literal);
            free(literal);
            return tok;
        }
        else
        {
            char *temp = (char *)malloc(sizeof(char) * 2);
            sprintf(temp, "%c", l->ch);
            tok = new_token(ILLEGAL, temp);
            free(temp);
        }
        break;
    }

    read_char(l);

    return tok;
}

void skip_white_spaces(lexer *l)
{
    while (l->ch == ' ' || l->ch == '\r' || l->ch == '\n' || l->ch == '\t')
    {
        read_char(l);
    }
}

int peek_char_is(lexer *l, char c)
{
    char ch = (char)fgetc(l->fptr);
    ungetc(ch, l->fptr);
    if (ch == c)
    {
        return 1;
    }
    return 0;
}

int is_digit(int c)
{
    return '0' <= c && c <= '9';
}

int is_letter(int c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || (c == '_');
}

char *read_identifier(lexer *l, int (*f)(int c))
{
    int i = 0;
    char *s = (char *)malloc(sizeof(char) * 20);

    while (f(l->ch))
    {
        s[i++] = l->ch;
        read_char(l);
    }
    s[i] = 0;

    char *rs = (char *)malloc(sizeof(char) * (i + 1));
    rs[i] = 0;
    memcpy(rs, s, i);
    free(s);

    return rs;
}

token new_token(char *t, char *l)
{
    token tok;

    tok.token_type = (char *)malloc(sizeof(t));
    memcpy(tok.token_type, t, sizeof(t));

    tok.literal = (char *)malloc(sizeof(l));
    memcpy(tok.literal, l, sizeof(l));

    return tok;
}

void free_lexer(lexer *l)
{
    free(l);
}