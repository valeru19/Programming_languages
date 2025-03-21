/*Написать программу для генератора лексических анализаторов, выводящую в консоль переданный токен*/

%{
#include <stdio.h>
%}

%%
[0-9]+ { printf("NUMBER: %s\n", yytext); }
"+" { printf("PLUS\n"); }
"-" { printf("MINUS\n"); }
"*" { printf("TIMES\n"); }
"/" { printf("DIVIDE\n"); }
"(" { printf("LPAREN\n"); }
")" { printf("RPAREN\n"); }
\n { printf("EOL\n"); }
[ \t] ; /* пропуск пробелов и табуляций */
. { printf("Неверный символ: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}