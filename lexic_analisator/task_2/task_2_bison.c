/*Описать грамматику, позволяющую вычислять значения арифметических выражений, 
состоящих из произвольного конечного количества целых чисел и знаков «+» и «-»*/

%{
    #include <stdio.h>
    #include <string.h>
    #include "lab3_2.tab.h"

    int yylex(void);
    void yyerror(const char *str);
    int main(int argc, char **argv);
%}

%token INTEGER 
%token SUM SUB MUL DIV
%token OBRACE EBRACE
%token EOL
%token NUMBER
%%
calclist: /* nothing */
| calclist exp EOL { printf("= %d\n", $2); }
;
exp: factor
| exp SUM factor { $$ = $1 + $3; }
| exp SUB factor { $$ = $1 - $3; }
;
factor: term
| factor MUL term { $$ = $1 * $3; }
| factor DIV term { $$ = $1 / $3; }
;
term: INTEGER
| OBRACE exp EBRACE { $$ = $2; }
;
%%
void yyerror(const char *str){
    fprintf(stderr,"Error: %s\n",str);
}
int main(int argc, char **argv){
    yyparse();
    return 0;
}