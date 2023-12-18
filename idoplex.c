%{
#include <stdio.h>
%}

%%

[0-9]+          { printf("Number: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
[-+*/=()]       { printf("Operator: %s\n", yytext); }

[ \t\n]         ; // Ignore whitespace characters

.               { printf("Invalid Character: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}
