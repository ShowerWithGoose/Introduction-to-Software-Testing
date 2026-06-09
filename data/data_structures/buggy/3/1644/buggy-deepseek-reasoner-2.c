#include<stdio.h>
#include<string.h>

int main()
{
    char s[200];
    scanf("%s",s);
    
    int i,k,t=0,m;
    for(i=0;i<(strlen(s));i++)
    {
        if(s[i]=='.')
        {
            k=i;
        }
        if(s[i]=='0')
        {
            t++;
        }
        else 
        {
            t=0;
        }
    }
    if(k>1||(k==1&& s[0]!='0'))
    {
        printf("%c",s[0]);
        printf(".");
        
        for(i=1;i<strlen(s)-t;i++)
        {
            if(i==k)
            continue;
            else
            printf("%c",s[i]);
        }
        printf("e%d",k-1);
    }
    else if(k=1) // @@ Assignment instead of comparison; should be k==1. This causes the else-if block to always execute when the first condition fails, leading to incorrect handling of numbers like "12.34" (which would incorrectly go here).
    {
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]!='0'&&s[i]!='.')
            {
                m=i-1;
                break;
            }
        }
        printf("%c",s[m+1]);
        if(strlen(s)==t+m+2) // @@ This condition is too restrictive; only handles cases with exactly one significant digit after leading zeros (e.g., "0.5", "0.05"). For numbers like "0.0012" it goes to else branch and fails to print the exponent.
        {
            printf("e-%d",m);
        }
        else
        {
            printf(".");
            for(i=m+2;i<strlen(s)-t;i++)
            {
                printf("%c",s[i]);
            }
            // @@ Missing exponent output. For numbers like "0.0012", the base is printed as "1.2" but the exponent (e-3) is not printed.
        }
    }
    return 0;
}