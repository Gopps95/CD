%{
#include <stdio.h>
%}

%%
^a.*   { printf("Accepted: %s\n", yytext); }
.      { printf("Rejected: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
