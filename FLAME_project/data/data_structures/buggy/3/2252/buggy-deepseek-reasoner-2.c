#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110];
int main()
{
    gets(s);
    int j;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            if(i==1)
            {
                if(s[i-1]=='0')
                {
                    for (j=i+1;s[j]!='\0';j++)
                    {
                        if(s[j]!='0')
                        {
                            printf("%ce-%d",s[j],j-1); // @@ This prints each non-zero digit separately, but scientific notation requires a single mantissa with one digit before decimal and the rest after, followed by one exponent. Instead, collect all digits after the first non-zero, place a decimal after the first digit, and print exponent once.
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s);
                }
            }
            else if(i>1)
            {
                printf("%c.",s[0]);
                for (int p=1;s[p]!='\0';p++)
                {
                    if(s[p]=='.')
                    {
                        continue;
                    }
                    else
                    {
                        printf("%c",s[p]);
                    }
                }
                printf("e%d",i-1);
            }
        }
    }
    return 0;
}