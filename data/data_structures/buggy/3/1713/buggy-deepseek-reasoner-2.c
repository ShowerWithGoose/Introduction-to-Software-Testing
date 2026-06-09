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
            for (int i = 1; i < len;i++) // @@ Missing decimal point: prints all digits after first without inserting '.', e.g., "123" becomes "123e2" instead of "1.23e2".
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
        num = len - 2; // @@ Incorrect exponent: should be -(number of zeros after decimal + 1), not len-2. For "0.00123", gives e-5 instead of e-3.
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