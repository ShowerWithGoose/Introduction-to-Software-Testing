#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int try(char *q)
{
    if(islower(*q)&&*(q+1)=='-'&&islower(*(q+2))&&*q<*(q+2))
    {
        for(int i=*q;i<*(q+2);i++)
        {
            printf("%c",i);
        }
        return 1;
    }
    if(isupper(*q)&&*(q+1)=='-'&&isupper(*(q+2))&&*q<*(q+2))
    {
        for(int i=*q;i<*(q+2);i++)
        {
            printf("%c",i);
        }
        return 1;
    }
    if(isdigit(*q)&&*(q+1)=='-'&&isdigit(*(q+2))&&*q<*(q+2))
    {
        for(int i=*q;i<*(q+2);i++)
        {
            printf("%c",i);
        }
        return 1;
    }
    return 0;
}

int main()
{
    char s[100000];
    char *p=s;
    scanf("%s",s);
    while(*p!='\0')
    {
        if(*(p+2)=='\0')
        {
            printf("%s",p);
            break;
        }
        if(try(p))
        {
            p+=2;
            if(*(p+1)!='-')
            {
                printf("%c",*p);
                p++;
            }
        }
        else
        {
            printf("%c",*p);
            p++;
        }
    }
    return 0;
}

