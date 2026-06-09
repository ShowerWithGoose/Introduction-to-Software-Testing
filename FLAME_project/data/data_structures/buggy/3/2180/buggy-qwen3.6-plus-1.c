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
                printf("%c.",s[k]); // @@ The output format requires one digit before the decimal point. The original code printed all significant digits without a decimal point in the correct position. We need to print the first significant digit, then a dot.
                for(j=k+1;j<strlen(s);j++) // @@ After printing the first significant digit and the dot, we should print the remaining significant digits. The original loop started from k, which would reprint the first digit.
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1);
            }
        }
    }
    return 0;
}