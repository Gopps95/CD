%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT

%%

E : E '+' T    { $$ = $1 + $3; }
  | T          { $$ = $1; }
  ;

T : T '*' F    { $$ = $1 * $3; }
  | F          { $$ = $1; }
  ;

F : '(' E ')'  { $$ = $2; }
  | DIGIT      { $$ = $1; }
  ;

%%

int yylex() {
    int c = getchar();
    if (c >= '0' && c <= '9') {
        yylval = c - '0';
        return DIGIT;
    }
    return c;
}

int yyerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    return 1;
}

int main() {
    yyparse();
    return 0;
}
