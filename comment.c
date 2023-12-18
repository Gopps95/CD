%{
#include <stdio.h>
int com = 0;
%}

%s COMMENT

%%

"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN 0; com++;}
<COMMENT>\n {com++;}
<COMMENT>. {;}

\n { ; }
. { ; }

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: <./a.out> <sourcefile>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yylex();

    printf("No of comment lines=%d\n", com);

    return 0;
}
