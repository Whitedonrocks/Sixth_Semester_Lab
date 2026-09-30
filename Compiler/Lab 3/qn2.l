/* Write a lex program to check whether given number is odd or even. */
%option noyywrap
%{
	#include<stdio.h>
%}

%%
[0-9]+[02468] {printf("The give number is even\n");}
[0-9]+[13579] {printf("The give number is odd\n");}
.* {printf("Invalid Please enter a number\n");};

%%
int main()
{
	printf("Enter the number\n");
	yylex();
	return 0;
}