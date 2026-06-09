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
            if(s[i-1]!='0') // @@ This condition incorrectly checks the digit immediately before the decimal point; it should check whether the first digit of the whole number is '0' (i == 1 && s[0] == '0'). For "10.5", s[i-1] = '0' triggers the else branch, but this number should be treated as a normal non-zero-leading number.
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
                for(j=k;j<strlen(s);j++) // @@ This loop prints all digits from the first non-zero digit to the end. If there is more than one digit (e.g., "0.123"), a decimal point should be placed after the first digit to form a valid base (e.g., "1.23"). The current code outputs "123e-1" instead of "1.23e-1".
                {
                    printf("%c",s[j]);
                }
                printf("e-%d",k-1);
            }
        }
    } // @@ The program does not handle the case where the input has no decimal point (integer). According to the problem, integers should be output as they are. The for loop ends without producing any output, which is an omission.
    return 0;
}