%{
#include <stdio.h>
%}

%%

"++"|"--" { printf("%s : Increment/Decrement Operator\n", yytext); }

"+="|"-="|"*="|"/="|"%=" { printf("%s : Compound Assignment Operator\n", yytext); }

"=="|"!="|"<="|">="|"<"|">" { printf("%s : Relational Operator\n", yytext); }

"&&"|"||"|"!" { printf("%s : Logical Operator\n", yytext); }

"=" { printf("%s : Assignment Operator\n", yytext); }

"+"|"-"|"*"|"/"|"%" { printf("%s : Arithmetic Operator\n", yytext); }

[ \t\n]+ ;

. { printf("%s : Invalid Operator/Symbol\n", yytext); }

%%

int main()
{
    printf("Enter operators:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}