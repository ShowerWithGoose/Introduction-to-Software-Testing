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
                            printf("%ce-%d",s[j],j-1); // @@ [This prints only the first non-zero digit and its exponent, then continues looping and prints every subsequent digit with its own incorrect exponent, leading to repeated malformed output like "9e-81e-9...". It should break after printing the full mantissa once.]
                        }
                    }
                }
                else if(s[i-1]!='0')
                {
                    printf("%se0",s); // @@ [This prints the original number with "e0", but the problem requires normalized scientific notation: one non-zero digit before decimal, rest after. For example, "5.3" should become "5.3e0", but this prints "5.3e0" only if input is like "5.3", yet it doesn't remove extra digits after normalization. However, the bigger issue is in the '0.x' branch above.]
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
                        printf("%c",s[p]); // @@ [This prints all digits after the first, including those after the decimal, but does not stop after forming a proper mantissa (should only include necessary significant digits without trailing zeros). However, the main flaw is that it never terminates the mantissa properly—it prints the entire number after the first digit, which may be correct in some cases, but combined with other logic errors, it fails on small numbers. The critical error is in the 0.x handling.]
                    }
                }
                printf("e%d",i-1);
            }
        }
    }
    return 0;
}