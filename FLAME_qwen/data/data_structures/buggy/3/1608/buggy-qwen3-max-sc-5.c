#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') // @@ [Assumes the decimal point is always at index 1, which fails for numbers with more than one digit before the decimal point (e.g., "123.45")]
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; // @@ [Incorrectly increments cnt after counting leading zeros; this leads to wrong indexing and exponent calculation]
            printf("%c", c[cnt + 1]); // @@ [Accesses c[cnt + 1] which may be out of bounds or skip the first non-zero digit incorrectly]
            if(c[cnt + 2] != '\0') printf("."); // @@ [Uses cnt + 2 for checking decimal point presence, which is based on flawed cnt logic]
            for(int i = cnt + 2; c[i] != '\0'; i++) // @@ [Starts printing from cnt + 2, likely skipping significant digits or causing undefined behavior]
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); // @@ [Exponent should be -(number of leading zeros + 1), but cnt already includes an extra increment]
        }
        else
        {
            printf("%se0", c); // @@ [Fails to normalize numbers like "5.67" into "5.67e0"; it just prints original input which may have multiple digits before decimal]
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
            if(c[cnt] != '0' && cnt > 0) // @@ [This condition sets flag only if a non-zero digit appears after index 0, but ignores cases where zeros are significant in middle (e.g., "102.3")]
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); // @@ [Only prints decimal point if flag is set, but scientific notation requires decimal point if there are digits after the first one]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ [Skips all zeros, including significant ones (e.g., in "102.3", the '0' is significant but gets omitted)]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1); // @@ [Exponent calculation assumes decimal point exists; if input has no decimal point (e.g., "123"), cnt becomes length of string, leading to wrong exponent]
    }
    return 0;
}