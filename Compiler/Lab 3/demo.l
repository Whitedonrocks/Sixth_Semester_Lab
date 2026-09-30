%option noyywrap
%{
	#include<stdio.h>
%}

%%
"Hi" {printf("Hello");}
.* {printf("Wrong input");}
%%
int main()
{
	printf("Enter String:");
	yylex();
	return 0;
}