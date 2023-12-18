#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isKeyword(char buffer[]) 
{
  int i, f;
    char keyword[32][10] = {"auto","break","case","continue","enum","extern","float","goto","else","return","static","char","const","do","double","for","if","int","long","register","short","signed","sizeof","struct","switch","typedef","union","unsigned","void","volatile","while"};
     for(i = 0; i < 32; i++) 
    {
        if(strcmp(keyword[i], buffer) == 0) 
        {
            f = 1;
            break;
        }
        else 
        {
            f = 0;
        }
    }
    return f;
}

int isFunction(char buffer[])
{
    if(strcmp(buffer, "printf") == 0 || strcmp(buffer, "scanf") == 0) 
    {
        return 1; 
    }
     return 0;
}

int main() 
{
    int i, j = 0;
    char buffer[20], ch, operator[] = "+-*/%=", symbol[] = "(){}[];'#<>.";
    FILE *fp;
    fp = fopen("in.txt", "r");

    if (fp == NULL) 
    {
       printf("Error\n");
    }

    while ((ch = fgetc(fp)) != EOF) 
    {
        if (ch == '#' && (ch = fgetc(fp)) == 'i' && (ch = fgetc(fp)) == 'n' && (ch = fgetc(fp)) == 'c' && (ch = fgetc(fp)) == 'l' && (ch = fgetc(fp)) == 'u' && (ch = fgetc(fp)) == 'd' && (ch = fgetc(fp)) == 'e') 
        {
            while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            continue;
        }

        for (i = 0; i < 6; i++) 
        {
            if (ch == operator[i]) 
            {
                printf("%c-operator\n", ch);
            }
        }
        for (i = 0; i < 12; i++) 
        {
            if (ch == symbol[i]) 
            {
                printf("%c-symbol\n", ch);
            }
        }

        if (isalnum(ch)) 
        {
            buffer[j++] = ch;
        } 
        else if (((ch == ' ') || (ch == '\n')) && (j != 0)) 
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1) 
            {
                printf("%s-keyword\n", buffer);
            }
            else if (isFunction(buffer) == 1) 
            {
                printf("%s-function\n", buffer);
            }
            else 
            {
                printf("%s-identifier\n", buffer);
            }
        }
    }
    fclose(fp);
    return 0;
}
