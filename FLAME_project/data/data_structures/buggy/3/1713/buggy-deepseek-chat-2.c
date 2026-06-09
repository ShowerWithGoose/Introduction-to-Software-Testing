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
        num = len - 2; // @@ Error: This calculation of num is incorrect for numbers like 0.00000009123456789012. It assumes the exponent is always len-2, but the exponent should be the number of zeros after the decimal point before the first non-zero digit, plus one. For input "0.00000009123456789012", len=20, num=18, but the correct exponent is -8 (i.e., 8 zeros after decimal before the first non-zero digit). The exponent should be -(position of first non-zero digit - 1), not len-2.
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
        printf("e-%d", num);
    }
    return 0;
}