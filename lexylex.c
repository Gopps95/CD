%{
int  nlines=0;
%}

DIGIT[0-9]
LETTER[a-z A-Z]
ID{LETTER}({LETTER}|{DIGIT})*
%%
\n ++nlines;
{DIGIT}+ {printf("An integer %s\n",yytext);}
{DIGIT}+"."{DIGIT}+ {printf("A floating point number%s\n",yytext);}
IF|THEN|ELSE|BEGIN|END|FOR|WHILE {printf("keyword%s\n",yytext);}
{ID} {printf("An identifier is %s\n",yytext);}
"+"|"-"|"*"|"/"|"="|"<"|">"|"<="|">=" {printf("an operator%s\n",yytext);}
%%
main()
{
printf("Enter expresion\n");
yylex();
printf("Number of lines=%d",nlines);
}