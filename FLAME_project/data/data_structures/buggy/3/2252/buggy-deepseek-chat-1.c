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
                            printf("%ce-%d",s[j],j-1); // @@ Error: This prints each non-zero digit separately with its own exponent, instead of collecting all digits after the first non-zero digit into the base and computing a single exponent. For input "0.00000009123456789012", it outputs multiple "e-..." fragments instead of "9.123456789012e-8".
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s); // @@ Error: This prints the entire original string including the decimal point, but the base should have only one digit before the decimal point. For example, "1.23" should become "1.23e0", but this prints "1.23e0" which is correct for that case, but the logic is incomplete for other cases.
                }
            }
            else if(i>1)
            {
                printf("%c.",s[0]); // @@ Error: This assumes the first character is the only digit before the decimal point, but for numbers like "12.34", it should output "1.234e1", not "1.234e1" (which is correct here), but the exponent calculation i-1 is correct. However, the loop that follows prints all remaining characters including trailing zeros, which violates the "no trailing zeros" rule.
                for (int p=1;s[p]!='\0';p++)
                {
                    if(s[p]=='.')
                    {
                        continue;
                    }
                    else
                    {
                        printf("%c",s[p]); // @@ Error: This prints all digits after the first digit, including trailing zeros, but the problem requires no trailing zeros in the base. Also, it does not handle the case where the number is an integer (no decimal point) or has only one digit before the decimal point.
                    }
                }
                printf("e%d",i-1); // @@ Error: The exponent calculation i-1 is correct for numbers like "12.34" (i=2, exponent=1), but the overall logic fails for numbers with leading zeros after the decimal point (e.g., "0.00123") because it doesn't handle the case where the first digit before the decimal is '0' and i>1 (which doesn't occur in valid input, but the logic is incomplete).
            }
        }
    }
    return 0;
}