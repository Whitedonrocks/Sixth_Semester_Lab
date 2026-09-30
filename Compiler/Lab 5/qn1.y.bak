%{
	#include<stdio.h>
%}

%token A B
%% 
S : A S B
  | ;
%%
void main()
{
    printf("Enter string: ");

    if (yyparse() == 0)
        printf("Valid string\n");
        getch();
}	
yyerror()
{
	printf("invalid input string");
}