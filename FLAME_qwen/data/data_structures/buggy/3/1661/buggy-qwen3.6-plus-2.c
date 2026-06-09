#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
char s[105];
int main()
{
    scanf("%s",s);
    int i=0,len=strlen(s),j,k=0,i1;
    if(s[0]=='0')
    {
        i++;
        while(s[i+1]=='0')
            i++;
        printf("%c.",s[i+1]); // @@ Unconditionally prints a decimal point even when there are no subsequent digits (e.g., input "0.1" outputs "1.e-1" instead of "1e-1"), violating the output format specification which requires an integer format for single-digit mantissas.
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i);
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1)
            i++;
        if(i==len-1)
        {
        while(s[len-1-k]=='0')
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++)
            printf("%c",s[j]);
        }
        printf("e%d",i);
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i);
        }
    }
    return 0; 
}