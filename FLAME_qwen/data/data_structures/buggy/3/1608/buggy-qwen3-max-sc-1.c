#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') @@ [Assumes the decimal point is always at index 1, which fails for numbers with more than one digit before the decimal point (e.g., "12.34")]
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; @@ [Incorrectly increments cnt after counting leading zeros; this leads to wrong offset when printing significant digit]
            printf("%c", c[cnt + 1]); @@ [Uses cnt+1 as index, which may go out of bounds or skip the first non-zero digit incorrectly]
            if(c[cnt + 2] != '\0') printf("."); @@ [Uses cnt+2 for checking next character, which is based on incorrect cnt logic]
            for(int i = cnt + 2; c[i] != '\0'; i++)
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); @@ [Exponent calculation is off by one due to extra cnt++]
        }
        else
        {
            printf("%se0", c); @@ [Fails to normalize numbers like "5.67" into "5.67e0"; should output "5.67e0" but also doesn't remove unnecessary trailing zeros or ensure single digit before decimal]
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
            if(c[cnt] != '0' && cnt > 0) @@ [This condition sets flag only if a non-zero digit appears after the first digit, but ignores cases where zeros are significant (e.g., "10.5" becomes "1.5e1" instead of "1.05e1")]
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); @@ [Only prints decimal point if there's a non-zero digit after first, but misses cases where zeros are significant and must be preserved]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') @@ [Skips all zeros after the first digit, which violates the requirement that all digits are significant; e.g., "102.3" becomes "123e2" instead of "1.023e2"]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1); @@ [Exponent is correct in form but base is wrong due to skipping zeros]
    }
    return 0;
}