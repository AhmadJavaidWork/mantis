#define IDENT "IDENT"
#define INT "INT"
#define ILLEGAL "ILLEGAL"

#define PLUS "+"
#define MINUS "-"
#define ASTERISK "*"
#define SLASH "/"
#define LT "<"
#define GT ">"
#define BANG "!"

#define ASSIGN "="
#define EQ "=="
#define NOT_EQ "!="

#define COMMA ","
#define COLON ":"
#define SEMI_COLON ";"

#define LPAREN "("
#define RPAREN ")"
#define LBRACE "{"
#define RBRACE "}"
#define LBRACKET "["
#define RBRACKET "]"

#define FUNCTION "FUNCTION"
#define LET "LET"
#define RETURN "RETURN"
#define TRUE "TRUE"
#define FALSE "FALSE"
#define IF "IF"
#define ELSE "ELSE"

typedef struct token
{
    char *token_type;
    char *literal;
} token;

char *lookup_keyword(char *literal);

void free_token(token t);