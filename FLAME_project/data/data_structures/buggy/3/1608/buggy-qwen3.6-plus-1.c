#include<stdio.h>

char c[10000], s[10000];

int main()
{
    scanf("%s", c);
    if(c[1] == '.')
    {
        if (c[0] == '0')
        {
            int j = 0, cnt = 0;
            for (int i = 2; c[i] != '\0'; i++)
            {
                if (c[i] == '0') cnt++;
                else break;
            }
            cnt++;
            printf("%c", c[cnt + 1]);
            if(c[cnt + 2] != '\0') printf(".");
            for(int i = cnt + 2; c[i] != '\0'; i++)
            {
                printf("%c", c[i]);
            }
            printf("e-%d", cnt);
        }
        else
        {
            printf("%se0", c);
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
        if(flag) printf(".");
        for(int i = 1; c[i] != '\0'; i++) // @@ The condition `c[i] != '0'` incorrectly filters out significant zeros that appear after the decimal point or within the number. It should only skip the decimal point character, preserving all other digits to maintain precision as required by the problem statement ("all digits are significant").
        {
            if(c[i] != '.' && c[i] != '0') // @@ This condition removes '0' digits from the output mantissa, which causes loss of significant digits (e.g., converting 87899.9999999999000999 to 8.78999999999999999 instead of 8.78999999999999000999). The check `c[i] != '0'` should be removed.
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1);
    }
    return 0;
}