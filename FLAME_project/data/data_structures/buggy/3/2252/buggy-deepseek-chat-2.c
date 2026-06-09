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
                            printf("%ce-%d",s[j],j-1); // @@ This line incorrectly prints each non-zero digit separately with its own exponent, instead of printing the entire mantissa and a single exponent. It also fails to handle digits after the first non-zero digit and does not include the decimal point in the output.
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s); // @@ This line prints the entire original string including the decimal point, but the expected output for numbers like "1.23" should be "1.23e0" (with the decimal point in the mantissa). However, the problem requires the base to have one digit before and after the decimal point, so this is correct for single-digit before decimal, but the code does not handle trailing zeros removal or the case where the number is an integer.
                }
            }
            else if(i>1)
            {
                printf("%c.",s[0]); // @@ This line prints the first digit and a decimal point, but does not handle the case where the first digit might be '0' (which should not happen per problem description, but the logic is fragile). Also, it does not remove trailing zeros from the mantissa.
                for (int p=1;s[p]!='\0';p++)
                {
                    if(s[p]=='.')
                    {
                        continue;
                    }
                    else
                    {
                        printf("%c",s[p]); // @@ This prints all remaining digits including trailing zeros, which violates the "no trailing zeros" requirement. Also, it does not handle the case where the number has only one digit before the decimal point (i==1 case already handled).
                    }
                }
                printf("e%d",i-1); // @@ This prints the exponent as the position of the decimal point minus one, which is correct for numbers like "123.45" (exponent 2), but does not account for leading zeros in numbers like "0.001" (which would require negative exponent calculation based on leading zeros).
            }
        }
    }
    return 0;
}