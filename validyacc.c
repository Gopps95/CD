%{
#include<stdio.h>
#include<ctype.h>
%}
%token DIGIT
%left '+''-'
%left '*''/'
%%
line:expr '\n' {printf("%d\n",$1);}
;
expr:expr'+'expr {$$=$1+$3;}
|expr'-'expr {$$=$1-$3;}
|expr'*'expr {$$=$1*$3;}
|expr'/'expr {$$=$1/$3;}
|'('expr')' {$$=($2);}
|'-'expr {$$=-$2;}
|DIGIT {$$=$1;}
;
%%
main()
{
printf("enter an expression\n");
yyparse();
}
yyerror(char *s)
{
printf("%s",s);
}
int yylex(void)
{
int c;
c=getchar();
if(isdigit(c))
{
yylval=c-'0';
return DIGIT;
}
return c;
}