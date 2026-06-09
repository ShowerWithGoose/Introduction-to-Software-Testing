#include<stdio.h>

int main()
{
    int e,i,j;
    char s[150]={0};
    gets(s);
    if(s[0]=='0')
    {
        i=2;
        while(s[i]=='0')
        {
            i++;
        }
        e=-i+1;
        // @@ The code prints the first significant digit but fails to print a decimal point afterwards, resulting in an integer base instead of a decimal base (e.g., "9..." instead of "9....").
        printf("%c",s[i]); // @@ [Missing decimal point after the first significant digit for numbers less than 1]
        i++;
        while(s[i]!='\0')
        {
            printf("%c",s[i]);
            i++;
        }
        printf("e%d",e);
    }
    else if(s[0]!='0'&&s[1]=='\0')
    printf("%ce0",s[0]);
    else
    {
        i=0;
        while(s[i]!='.')
        {
            i++;
        }
        e=i-1;
        j=2;
        printf("%c.",s[0]);
        while(s[j]!='\0')
        {
            if(s[j]!='.')
            {
            printf("%c",s[j]);
            j++;
            }
            else
            j++;
        }
        printf("e%d",e);
    }
    return 0;
}