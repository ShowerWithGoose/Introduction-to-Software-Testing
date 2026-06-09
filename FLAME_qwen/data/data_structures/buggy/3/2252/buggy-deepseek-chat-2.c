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
                            printf("%ce-%d",s[j],j-1); // @@ [Error: This prints only the first non-zero digit after the decimal point, but the problem requires the base to include all significant digits after the decimal point (without trailing zeros). Also, the exponent calculation is incorrect; it should be -(j-i) instead of j-1. Additionally, the loop does not handle the case where there are more digits after the first non-zero digit, and it breaks after printing only one character.]
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s); // @@ [Error: This prints the entire input string including the decimal point, but the problem requires the base to have exactly one digit before the decimal point and no trailing zeros. For input like "1.23", the output should be "1.23e0", but this code prints "1.23e0" which is correct for this case. However, for input like "12.3", this branch is not reached because i==1 is false, so it's fine. But the logic is incomplete: it does not handle cases where the number has more than one digit before the decimal point and the first digit is non-zero (e.g., "12.3" should go to the else if(i>1) branch, which is correct).]
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
                printf("e%d",i-1); // @@ [Error: The exponent should be i-1, which is correct for numbers like "12.3" (i=2, exponent=1). However, the base output includes all digits from the original number except the decimal point, which may include leading zeros after the decimal point (e.g., for "10.01", it prints "1.001e1", which is correct). But the problem states that the input has no trailing zeros, so this is fine. However, the code does not handle the case where the number is like "0.001" (i==1 and s[0]=='0'), which is handled in the first branch, but that branch has errors as noted.]
            }
        }
    }
    return 0;
}