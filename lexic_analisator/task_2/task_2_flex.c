/*Описать грамматику, позволяющую вычислять значения арифметических выражений, 
состоящих из произвольного конечного количества целых чисел и знаков «+» и «-»*/
%{
#include <stdio.h>
#include <string.h>
#include "lab3_2.tab.h"

void exit_ctrlq();
void Errors();
%}

%%
    [0-9]+ { yylval=atoi(yytext); return INTEGER; }
    "+" { return SUM; }
    "-" { return SUB; }
    "*" { return MUL; }
    "/" { return DIV; }
    "(" { return OBRACE; }
    ")" { return EBRACE; }
    "\n" { return EOL; }
    [ \t]+ ; /* skip whitespaces */
    . { Errors();}
    "exit" {exit_ctrlq();}
%%

int yywrap(){
    return 1;
}

void Errors(){
    printf("Something went wrong");
}

void exit_ctrlq(){
    exit(0);
}