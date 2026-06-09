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
            if(s[i-1]!='0') // @@ Error: This condition incorrectly treats numbers like "10.2" (multiple digits before decimal with last digit zero) as if they are less than 1. It should be based on the number of digits before decimal (i>=2) instead of the value of the digit before the dot.
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
                for(j=k;j<strlen(s);j++) // @@ Error: This loop prints all digits from the first non‑zero onward without inserting a decimal point after the first digit. The correct output for "0.00000009123456789012" should be "9.123456789012e-8", not "9123456789012e-8".
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1);
            }
        }
    }
    return 0;
}