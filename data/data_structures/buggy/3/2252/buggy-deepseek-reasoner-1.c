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
                            printf("%ce-%d",s[j],j-1); // @@ This prints only the first non-zero digit and exponent, missing the decimal point and subsequent digits. It also does not break after printing, causing multiple outputs for each non-zero digit. Should print a decimal point after the first non-zero digit, then the remaining digits, then the exponent, and then break out of the loop.
                        }
                    } // @@ After the loop, the code should return or break to avoid further processing, but it continues the outer loop, which may lead to incorrect behavior.
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