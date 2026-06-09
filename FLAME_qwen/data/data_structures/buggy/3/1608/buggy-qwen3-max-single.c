#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') @@ // This condition assumes the decimal point is always at index 1, which fails for numbers with more than one digit before the decimal point (e.g., "12.34").
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; @@ // Incorrectly increments cnt after counting leading zeros; this leads to wrong indexing and exponent calculation.
            printf("%c", c[cnt + 1]); @@ // Accesses c[cnt + 1], which may be out of bounds or skip the first non-zero digit incorrectly.
            if(c[cnt + 2] != '\0') printf(".");
            for(int i = cnt + 2; c[i] != '\0'; i++)
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt);
        }
        else
        {
            printf("%se0", c); @@ // Fails to convert numbers like "5.67" into proper scientific notation (should be "5.67e0", but this prints "5.67e0" only if input already matches format; however, per problem, single-digit before decimal should output without extra digits after unless needed—but more critically, this branch doesn't handle normalization correctly for all cases).
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
            if(c[cnt] != '0' && cnt > 0)
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); @@ // The logic for deciding whether to print a decimal point is flawed—it only checks if there's a non-zero digit after the first, but ignores digits that are zero but significant (problem states all digits are significant, so zeros between non-zeros must be preserved).
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') @@ // Incorrectly skips all '0' digits, violating the requirement that all digits are significant and must appear in the mantissa.
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1);
    }
    return 0;
}