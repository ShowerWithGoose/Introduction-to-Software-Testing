#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') // @@ [This condition assumes the decimal point is always at index 1, which fails for numbers like "123.45" or "0.00123" where the decimal point may be elsewhere.]
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; // @@ [Incorrectly increments cnt after counting leading zeros; this leads to wrong offset when printing significant digit.]
            printf("%c", c[cnt + 1]); // @@ [Accesses c[cnt + 1], which may be out of bounds or skip the first non-zero digit incorrectly. Should be c[2 + cnt] or similar.]
            if(c[cnt + 2] != '\0') printf("."); // @@ [Same indexing issue; may access invalid memory or miss digits.]
            for(int i = cnt + 2; c[i] != '\0'; i++) // @@ [Starts printing from wrong index due to earlier miscalculation of cnt.]
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); // @@ [Exponent should be -(number of leading zeros + 1), but cnt already includes an extra increment, making exponent off by one.]
        }
        else
        {
            printf("%se0", c); // @@ [Fails to normalize the number into scientific notation format; e.g., "5.3" should become "5.3e0", but this prints "5.3e0" only if input is exactly "X." format, and doesn't handle cases like "12.3". Also, per spec, if base has more than one digit before '.', it must be normalized.]
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
            if(c[cnt] != '0' && cnt > 0) // @@ [This flag logic is flawed: it sets flag=1 if any non-zero digit appears after the first, but trailing zeros before '.' are not handled correctly, and it doesn't account for normalization requirement.]
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); // @@ [Incorrectly decides whether to print decimal point based on presence of non-zero digits after first, but scientific notation requires exactly one non-zero digit before decimal, then rest after — this logic doesn't enforce that structure.]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ [Skips all zeros entirely, including significant ones that come after non-zero digits (e.g., "102.3" becomes "1.23", losing the zero). This violates the requirement that all digits are significant and must be preserved.]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1); // @@ [Exponent calculation assumes decimal point exists and cnt is its position, but if there's no decimal point in input (which shouldn't happen per problem, but code doesn't validate), this fails. Also, even with decimal, skipping zeros breaks digit count.]
    }
    return 0;
}