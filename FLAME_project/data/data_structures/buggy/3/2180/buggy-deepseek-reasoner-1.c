#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
    char s[105];
    int i,j,k;
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            if(s[i-1]!='0')
            {
                printf("%c.",s[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
            }
            else
            {
                for(j=2;j<strlen(s);j++)
                {
                    if(s[j]!='0')
                    {
                        k=j;
                        break;
                    }
                }
                for(j=k;j<strlen(s);j++) // @@ Error: This loop prints all digits from the first non‑zero to the end without inserting a decimal point after the first digit, causing the base to be a single integer instead of a proper decimal (e.g., outputs "9123456789012" instead of "9.123456789012").
                {
                    printf("%c",s[j]); // @@ Error: Should first print s[k], then if there are more digits, print a '.' and then the rest (excluding trailing zeros). Currently prints all digits consecutively, which is incorrect.
                }
                printf("e-%d",k-1); // The exponent is correct but the base printed above is wrong.
            }
        }
    }
    return 0;
}