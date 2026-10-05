%{
#include <stdio.h>

int yylex();
int yyerror(char *s);
%}

%token VARIABLE
%token INVALID

%%

input:
      VARIABLE   { printf("Valid Variable\n"); }
    | INVALID    { printf("Invalid Variable\n"); }
    ;

%%

int yyerror(char *s)
{
    return 0;
}

int main()
{
    printf("Enter a variable: ");
    yyparse();
    return 0;
}