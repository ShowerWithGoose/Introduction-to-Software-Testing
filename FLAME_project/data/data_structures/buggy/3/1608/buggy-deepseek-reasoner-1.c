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
        for(int i = 1; c[i] != '\0'; i++)
        {
            if(c[i] != '.' && c[i] != '0') // @@ This condition incorrectly skips all zero digits, including significant zeros that are not trailing. For numbers like "87899.9999999999000999", the three zeros after the nines are significant because they are followed by non‑zero digits. Removing them changes the number's precision.
            {
                printf("%c", c[i]);
            }
        }
        printf("e%d", cnt - 1);
    }
    return 0;
}