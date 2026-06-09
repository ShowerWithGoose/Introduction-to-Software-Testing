#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') // @@ [This condition assumes the decimal point is always at index 1, which fails for numbers with more than one digit before the decimal point (e.g., "123.45").]
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; // @@ [Incorrectly increments cnt after counting leading zeros; should not increment here because cnt already represents the number of leading zeros after '0.']
            printf("%c", c[cnt + 1]); // @@ [Accesses c[cnt + 1], which may be out of bounds or skip the first non-zero digit incorrectly. Should use c[2 + cnt] instead.]
            if(c[cnt + 2] != '\0') printf("."); // @@ [Uses cnt + 2 which is based on incorrect cnt logic and may access invalid memory or miss digits.]
            for(int i = cnt + 2; c[i] != '\0'; i++) // @@ [Starts printing from cnt + 2, which is likely beyond the first significant digit due to earlier cnt misuse.]
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); // @@ [Exponent should be -(cnt) but due to extra cnt++ it becomes off by one; correct exponent is -(number of leading zeros + 1).]
        }
        else
        {
            printf("%se0", c); // @@ [Fails to convert numbers like "5.3" into proper scientific notation "5.3e0"; it just prints original input which may have multiple digits before decimal.]
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
            if(c[cnt] != '0' && cnt > 0) // @@ [This flag logic is flawed: it sets flag=1 only if a non-zero digit appears after position 0, but ignores cases where trailing zeros after decimal should be preserved as significant. Also, it doesn't handle removal of decimal point correctly.]
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); // @@ [Conditionally prints '.' based on flawed flag; may omit decimal when needed or include it unnecessarily.]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ [Skips all '0' digits anywhere in the number, which violates the requirement that all digits are significant and must be preserved. Trailing zeros after decimal are significant and should not be dropped.]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1); // @@ [Exponent calculation assumes cnt is length before '.', which is correct, but the mantissa printed is wrong due to skipping zeros, making the whole output invalid.]
    }
    return 0;
}