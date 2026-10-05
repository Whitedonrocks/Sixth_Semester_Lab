%{
#include <stdio.h>
%}

%%

^[ \t]*([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+)[ \t]*([+*/%-][ \t]*([a-zA-Z_][a-zA-Z0-9_]*|[0-9]+)[ \t]*)+[ \t]*$ { printf("Valid arithmetic expression.\n"); }

.* { printf("Invalid arithmetic expression.\n"); }

%%

int main()
{
    printf("Enter an arithmetic expression:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}