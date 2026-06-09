#include <stdio.h>
#include <string.h>
int main()
{
    char s[105] = {""};
    char ans[101] = {""};
    scanf("%s", s);
    int len = strlen(s);
    int num = 0;
    if(s[0]>'0')
    {
        printf("%c", s[0]);
        int mark = 0;
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '.')
            {
                num = i - 1;
                mark = 1;
                break;
            }
        }

        if(mark==0)
        {
            num = len - 1;
            for (int i = 1; i < len;i++)
            {
                printf("%c", s[i]);
            }
        }
        else
        {
            printf(".");
            for (int i = 1; i < len; i++)
            {
                if(s[i]!='.')
                printf("%c", s[i]);
            }
        }
        printf("e%d", num);
    }
    else if(s[0]=='0')
    {
        num = len - 2; // @@ Error: For numbers like 0.001, the exponent should be negative based on the number of leading zeros, not len-2. For example, 0.001 should be 1e-3, but len-2 gives 1 (since len=5, 5-2=3, which is correct here, but for 0.0... it fails). However, the main issue is that the exponent calculation is incorrect for cases like 0.123 (should be 1.23e-1, but len-2=1, which is correct) but for 0.0123 (len=6, len-2=4, but exponent should be -2). The logic does not account for leading zeros after the decimal point.
        int flag = 0;
        for (int i = 2; i < len;i++)
        {
            if(s[i]!='0'&&flag==0)
            {
                printf("%c", s[i]);
                flag = 1;
                if (i < len - 1)
                    printf(".");
                continue;
            }

            if(flag==1)
                printf("%c", s[i]);
        }
        printf("e-%d", num); // @@ Error: The exponent should be based on the position of the first non-zero digit after the decimal point, not len-2. For example, input "0.001" should output "1e-3", but this code outputs "1e1" (since len=5, len-2=3, but the loop prints "1" and then "e-3" which coincidentally works for this case, but for "0.010" it would fail because len-2=3 but exponent should be -2). The exponent calculation is fundamentally wrong.
    }
    return 0;
}