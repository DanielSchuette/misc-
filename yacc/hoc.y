%{
#define YYSTYPE double /* data type of yacc stack */
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
list:   /* nothing */
    | list '\n'
    | list expr '\n'    { printf("\t%.8g\n", $2); }
    ;
expr:   NUMBER          { $$ = $1; }
    | expr '+' expr     { $$ = $1 + $3; }
    | expr '-' expr     { $$ = $1 - $3; }
    | expr '*' expr     { $$ = $1 * $3; }
    | expr '/' expr     { $$ = $1 / $3; }
    | '(' expr ')'      { $$ = $2; }
    ;
%%
/* end of grammar */

#include <stdio.h>
#include <ctype.h>

char *progname;
int lineno = 1;

int main(int argc, char *argv[])
{
    progname  = argv[0];
    yyparse();
    return 0;
}

int yylex(void)
{
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;
    if (c == EOF)
        return 0;
    if (c == '.' || isdigit(c)) {   /* c is a number */
        ungetc(c, stdin);        /* put char back */
        scanf("%lf", &yylval);      /* read double from stdin */
        return NUMBER;              /* defined by yacc */
    }
    if (c == '\n')
        lineno++;
    return c; /* c is a token */
}

yyerror(char *s)
{
    warning(s, (char *) 0);
}

warning(char *s, char *t)
{
    fprintf(stderr, "%s: %s", progname, s);
    if (t)
        fprintf(stderr, " %s", t);
    fprintf(stderr, " near line %d\n", lineno);
}
