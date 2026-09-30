%{
    #include<stdio.h>
    int yylex();
    int yyerror();
%}

%token NUM ID
%left '+' '-'
%left '*' '/'

%%
E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | NUM
  | ID
  ;
%%

int main()
{
    printf("Enter expression: ");

    if (yyparse() == 0)
        printf("Valid expression\n");

    return 0;
}

int yyerror()
{
    printf("Invalid expression\n");
    return 0;
}