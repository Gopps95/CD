%{
#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9_]*   { printf("Identifier: %s\n", yytext); count++; }
.                       ; // Ignore other characters

%%

int count = 0;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    yylex();

    printf("Number of Identifiers: %d\n", count);

    fclose(yyin);

    return 0;
}
