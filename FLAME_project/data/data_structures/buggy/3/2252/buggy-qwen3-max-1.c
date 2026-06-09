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
                            printf("%ce-%d",s[j],j-1); // @@ [This prints only the first non-zero digit and its exponent, then continues looping and prints every subsequent digit with its own incorrect exponent, leading to repeated "e" outputs. It should break after printing the full mantissa once.]
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s); // @@ [This prints the entire original string including the decimal point and all digits, which violates the requirement that scientific notation must have exactly one non-zero digit before the decimal point and no trailing zeros. Also, it doesn't format the mantissa correctly (e.g., "12.34" becomes "12.34e0" instead of "1.234e1").]
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
                        printf("%c",s[p]); // @@ [This prints all digits after the first without stopping, including trailing zeros if any (though problem says none), but more critically, it doesn't limit the mantissa to significant digits only in normalized form. However, the bigger issue is that this branch assumes the number has more than one digit before '.', but doesn't handle cases where leading digits might be zero (which shouldn't happen per problem, but logic is fragile). Still, the main bug is in the i==1 && s[0]=='0' branch.]
                    }
                }
                printf("e%d",i-1);
            }
        }
    }
    return 0;
}