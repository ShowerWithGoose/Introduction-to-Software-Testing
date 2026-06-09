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
        while(s[i]!='\0')
        {
            printf("%c",s[i]); // @@ Missing decimal point after first significant digit when multiple digits.
            i++;
        }
        printf("e%d",e);
    }
    else if(s[0]!='0'&&s[1]=='\0') // @@ This branch is unnecessary for valid inputs (which always contain a decimal point) and may produce incorrect output for single-digit numbers without a decimal point.
    printf("%ce0",s[0]);
    else
    {
        i=0;
        while(s[i]!='.')
        {
            i++;
        }
        e=i-1;
        j=2; // @@ Should be j=1 to include the digit at s[1] (second digit of the integer part) in the base.
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