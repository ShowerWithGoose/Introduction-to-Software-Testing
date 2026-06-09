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
                for(j=k;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1); // @@ Error: The exponent should be k-2, not k-1, because the decimal point is at index 1 (after '0.'), so the number of zeros after the decimal point before the first non-zero digit is k-2.
            }
        }
    }
    return 0;
}