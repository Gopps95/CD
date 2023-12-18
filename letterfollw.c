LEX PROGRAM
%{
#include"y.tab.h"
%}
%%
[a-zA-Z_] {return ALPHA;}
[0-9]+ {return DIGIT;}
"\n" {return ENTER;}
. {return ER;}
%%
yywrap()
{}


YACC PROGRAM
%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ALPHA DIGIT ENTER ER
%%
var:v ENTER {printf("valid Variable \n");exit(0);}
v:ALPHA exp1
exp1:ALPHA exp1|DIGIT exp1|;
%%
yyerror()
{
printf("invalid variable \n");
}
main()
{
printf("enter the expression");
yyparse();
}

