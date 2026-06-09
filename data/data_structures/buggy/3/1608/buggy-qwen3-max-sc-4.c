#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') // @@ [Assumes the number always has at least two characters and that the decimal point is at index 1, which fails for numbers like "123.45" or "0.001"]
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; // @@ [Incorrectly increments cnt after counting leading zeros; this leads to wrong offset when printing significant digit]
            printf("%c", c[cnt + 1]); // @@ [Uses cnt+1 as index, which may go out of bounds or skip the first non-zero digit incorrectly]
            if(c[cnt + 2] != '\0') printf("."); // @@ [Uses cnt+2 for checking next character, which is based on incorrect cnt logic and may access invalid memory]
            for(int i = cnt + 2; c[i] != '\0'; i++) // @@ [Starts printing from cnt+2, which likely skips required digits or accesses garbage]
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); // @@ [Exponent should be -(number of leading zeros + 1), but cnt already includes an extra increment, making exponent off by one]
        }
        else
        {
            printf("%se0", c); // @@ [Fails to normalize numbers like "5.67" into "5.67e0"; it just prints original input which may have more than one digit before decimal]
        }
    }
    else
    {
        int cnt,flag = 0;
        for(cnt = 0; c[cnt] != '\0'; cnt++)
        {
            if(c[cnt] == '.')
            {
                break;
            }
            if(c[cnt] != '0' && cnt > 0) // @@ [This condition sets flag only if a non-zero digit appears after position 0, but ignores cases where trailing digits after decimal are all zero (though problem says no trailing zeros), and more critically, doesn't handle normalization correctly]
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); // @@ [Only prints decimal point if there's a non-zero digit beyond first, but scientific notation requires decimal point if there are any additional significant digits, even if they come after a decimal in input]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ [Skips all zeros anywhere in the number, which is wrong because zeros between significant digits (e.g., "102.3") must be preserved]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1); // @@ [Exponent calculation assumes decimal point exists and is at position cnt, but if input has no decimal point (e.g., "123"), cnt will be length of string and exponent becomes too large]
    }
    return 0;
}