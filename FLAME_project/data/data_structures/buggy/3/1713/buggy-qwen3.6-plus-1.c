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
        num = len - 2; // @@ The exponent calculation is incorrect. It assumes all digits after '0.' are significant or counts total length incorrectly. For "0.000...09...", the exponent should be -(position of first non-zero digit - 1). Here, it calculates based on string length minus 2, which doesn't account for leading zeros after the decimal point correctly relative to the first significant digit.
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
        printf("e-%d", num); // @@ Because 'num' was calculated incorrectly above, the printed exponent is wrong. It should be the negative of the number of positions the decimal point moved to the right to get just after the first non-zero digit.
    }
    return 0;
}