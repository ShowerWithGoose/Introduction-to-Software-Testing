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
        printf("%c.",s[i+1]); // @@ [This always prints a decimal point even when there are no digits after it, e.g., for "0.9" it prints "9." instead of "9"]
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
        printf("%c.",s[0]); // @@ [This prints a decimal point even when trailing zeros have been removed and no fractional digits remain, which violates the output format requiring no decimal point for integer base]
        for(j=1;j<i+1-k;j++)
            printf("%c",s[j]);
        }
        printf("e%d",i);
        }
        else
        {
            printf("%c.",s[0]); // @@ [This always prints a decimal point even if all digits after the first are zero or if only one digit exists, but per problem statement, if the base is an integer (only one significant digit), it should not have a decimal point]
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