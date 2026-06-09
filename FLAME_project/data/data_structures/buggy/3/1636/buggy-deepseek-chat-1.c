#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    scanf("%s",&s);
    int i,j;
    if(s[1]=='.')
    {
        if(s[0]!='0')
        {
            for(i=0;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            printf("e0");    
        }
        else
        {
            for(i=2;i<strlen(s);i++)
            {
                if((s[i]!='0')&&(i!=strlen(s)-1))
                {
                    printf("%c.",s[i]);
                    for(j=i+1;j<strlen(s);j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("e%d",i-1); // @@ Error: The exponent should be negative for numbers less than 1. Here, i-1 is positive (e.g., for 0.00000009123456789012, i=9, so it prints e8 instead of e-8). The correct exponent should be -(i-1) or -(i-2) depending on the position of the first non-zero digit.
                    break;
                }
                else if(i==strlen(s)-1)
                {
                    printf("%ce-%d",s[i],i-1);
                }
            }
        }
    }
    else
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
                printf("%c.",s[0]);
                for(j=1;j<=i-1;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
                break;
            }
        }
    }
    return 0;
}