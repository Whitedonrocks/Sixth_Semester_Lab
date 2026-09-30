 /* Write a lex program to check whether given input is negative or positive.*/
%option noyywrap
%{
	#include<stdio.h>
%}

%%
-[0-9]+  {printf("The number is negative\n");}
[0-9]+ {printf("The number is positive\n");}
.* {printf("Invalid Please enter a number\n");};
%%
int main()
{	
	printf("Enter the number\n");
	yylex();
	return 0;
}
