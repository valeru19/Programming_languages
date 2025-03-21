/*Описать грамматику, позволяющую проводить трансляцию арифметических выражений,
 состоящих из вещественных чисел, знаков «+», «-», «*», «/» и скобок из инфиксной записи в постфиксную.*/
%{
#include <stdio.h>
#include "lab3_3.tab.h"
void Errors();
%}


%option noyywrap


%%

[0-9]+(\.[0-9]+)?   { yylval.number = atof(yytext); return NUMBER; }
[-+*/(){}]          { return yytext[0]; }
\n                  { return EOL; }
[ \t]               { /* ignore whitespace */ }
.                   { Errors(); }

%%

void Errors(){
    printf("Something went wrong");
}