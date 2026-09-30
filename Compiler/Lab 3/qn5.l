/* Write a lex program to check whether given input is a vlaid email or not. */
%option noyywrap
%{
	#include<stdio.h>
%}

%%
([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,3}) {printf("The give input is a valid email address.\n");}
.* {printf("Invalid Please enter a valid email address\n");};

%%
int main()
{
	printf("Enter your email\n");
	yylex();
	return 0;
}