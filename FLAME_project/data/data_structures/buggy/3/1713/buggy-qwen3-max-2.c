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
        num = len - 2; // @@ [The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at index 9 (0-based), so the exponent should be -(9 - 1) = -8, but this code sets num = len - 2 = 20 - 2 = 18, leading to e-18 or similar wrong value. The correct exponent is the negative of (position of first non-zero after decimal - 1).]
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
        printf("e-%d", num); // @@ [Because 'num' was incorrectly computed as len - 2 instead of the actual offset of the first significant digit, the exponent printed is wrong. For the given test case, it outputs e-20 instead of e-8.]
    }
    return 0;
}