#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.') @@ [Assumes input always has at least two characters and that the decimal point is at index 1, which fails for numbers like "123.45" or "0.001"]
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++; @@ [Incorrectly increments cnt after counting leading zeros; should not increment here because cnt already represents number of leading zeros after '0.']
            printf("%c", c[cnt + 1]); @@ [Accesses c[cnt + 1], which may be out of bounds if all digits after decimal are zero or if string is short; also logic misaligned with intended first non-zero digit]
            if(c[cnt + 2] != '\0') printf("."); @@ [Similarly risks out-of-bounds access and incorrect placement of decimal point]
            for(int i = cnt + 2; c[i] != '\0'; i++)
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt); @@ [Exponent should be -(number of leading zeros + 1), but cnt was incremented incorrectly, so exponent is off by one]
        }
        else
        {
            printf("%se0", c); @@ [Fails to normalize the number; e.g., "5.3" should become "5.3e0", but this prints "5.3e0" only if input is exactly one digit before decimal. However, condition c[1]=='.' allows multi-digit like "12.3" to enter this branch, which violates scientific notation rules (must have one non-zero digit before decimal)]
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
            if(c[cnt] != '0' && cnt > 0) @@ [This flag logic is flawed: it sets flag=1 if any non-zero digit appears after the first, but trailing zeros before decimal are significant per problem statement and should be printed. Also, flag is used to decide whether to print '.', but even if all subsequent digits are zero (e.g., "500."), we still need to output "5.00e2", but this skips zeros entirely]
            {
                flag = 1;
            }
        }
        printf("%c", c[0]);
        if(flag) printf("."); @@ [Only prints '.' if there's a non-zero digit after first, but problem states all digits are significant, so even zeros must be preserved and decimal point shown if there are digits after first]
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') @@ [Skips all zeros after first digit, violating the requirement that all digits are significant; e.g., "102.3" becomes "123" instead of "1.023"]
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1); @@ [Exponent calculation assumes decimal point exists; if input has no decimal point (e.g., "123"), cnt will be length of string, and exponent is correct, but the digit processing is wrong due to skipping zeros]
    }
    return 0;
}