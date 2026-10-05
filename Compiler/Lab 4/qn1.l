%{
#include <stdio.h>
%}

%%

"int"|"float"|"char"|"double"|"if"|"else"|"for"|"while"|"return"|"void" { printf("%s : Keyword\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* { printf("%s : Identifier\n", yytext); }

[0-9]+ { printf("%s : Number\n", yytext); }

[ \t\n]+ ;

. { printf("%s : Invalid/Other\n", yytext); }

%%

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}