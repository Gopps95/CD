%{
#include<stdio.h> 
int posint = 0, negint = 0, posfraction = 0, negfraction = 0;
%} 

%% 

[-][0-9]+ { negint++; } 
[+]?[0-9]+ { posint++; } 
[+]?[0-9]*\.[0-9]+ { posfraction++; } 
[-][0-9]*\.[0-9]+ { negfraction++; } 

%% 

int yywrap() { 
    return 1; 
} 

int main() { 
    char input[100]; 
    
    printf("Enter a string: "); 
    scanf("%s", input); 

    yy_scan_string(input); 
    yylex(); 

    printf("No of +ve integers=%d\n No of –ve integers=%d\n No of +ve fractions=%d\n No of –ve fractions=%d\n", posint, negint, posfraction, negfraction); 
    
    return 0; 
}
