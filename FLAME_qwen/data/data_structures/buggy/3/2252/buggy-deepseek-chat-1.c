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
                            printf("%ce-%d",s[j],j-1); // @@ [Error: This prints only the first non-zero digit after the decimal point, but the problem requires the base to include all significant digits after the decimal point (without trailing zeros). Also, the exponent calculation is incorrect; it should be -(j-i) instead of j-1. Additionally, the loop does not handle the case where there are more digits after the first non-zero digit, and it breaks after printing only one digit, missing the rest of the mantissa.]
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s); // @@ [Error: This prints the entire input string including the decimal point, but the problem requires the base to have exactly one digit before the decimal point and one digit after (if decimal), or be an integer. For input like "1.23", the output should be "1.23e0", but this prints "1.23e0" which is correct for this case. However, for input like "12.34", this branch is not taken because i==1 is false, so it's fine. But the logic is incomplete: it does not handle cases where the number has more than one digit before the decimal point and the first digit is non-zero (e.g., "12.34" should go to the else if(i>1) branch, which is correct).]
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
                printf("e%d",i-1); // @@ [Error: The exponent should be i-1 only if the decimal point is after the first digit. For example, input "12.34" has i=2, so exponent is 1, which is correct. However, this branch does not handle the case where the first digit is '0' (e.g., "0.123") because i==1 would be true, so it goes to the first branch. But for inputs like "0.00123", i==1 and s[i-1]=='0', so it goes to the inner if, which has the buggy loop. Also, the loop prints all digits after the decimal point including trailing zeros, but the problem states there are no trailing zeros, so it's acceptable. However, the base should not have a decimal point if there is only one significant digit after the decimal point? Actually, the problem says the base is either a decimal or an integer. For "12.34", the base should be "1.234" (one digit before and after decimal), but this code prints "1.234" which is correct. But for "100.0" (though trailing zeros are not allowed per problem), this would print "1.000e2" which is wrong because trailing zeros should not appear. Since input has no trailing zeros, this is fine.]
            }
        }
    }
    return 0;
}