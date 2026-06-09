#include <stdio.h>
char str[10000];
int main()
{
    gets(str);
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
        if(str[i+1]=='\0') // @@ This condition omits exponent for single digit fractional numbers; exponent should always be printed.
        {
            printf("%c",str[i]); // @@ Missing exponent after printing the digit; should include "e-%d" with exponent.
        }
        else
        {
            printf("%c.",str[i]);
            for(j=i+1;str[j]!='\0';j++)
            {
                printf("%c",str[j]);
            }    
            printf("e");
            printf("%d",i-1); // @@ Missing negative sign; exponent should be negative for numbers less than 1, so use "e-%d".
        }
    }
    else if(str[1]=='.')
    {
        for(i=0;str[i]!='\0';i++)
        {
            printf("%c",str[i]);
        }
        printf("e0");
    }
    else
    {
        for(i=0;str[i]!='.';i++);
        printf("%c.",str[0]);
        for(j=1;j<i;j++)
        {
            printf("%c",str[j]);
        }
        for(j=i+1;str[j]!='\0';j++)
        {
            printf("%c",str[j]);
        }
        printf("e");
        printf("%d",i-1);
    }
    return 0;
}