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
        // @@ The code prints all remaining digits without inserting a decimal point after the first significant digit.
        // @@ For input "0.00000009123456789012", the first significant digit is '9' at index i.
        // @@ It should print "9." followed by the rest, but it prints "9123456789012".
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