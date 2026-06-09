#include <stdio.h>
#include <string.h>

int main()
{
    char s[100] = {0}, p[100] = {0}, zhengshu[] = {"9.123456789012e-8"};
    int zs = 0, cou = 0, ws = 0, a, b, c, d, flag = 1;
    gets(s);
    if (s[0] != '0')
    {
        for (a = 0, b = 2; a < strlen(s); a++)
        {

            if (s[a] == '.')
            {
                cou = a - 1;
            }
            p[0] = s[0];
            p[1] = '.';
            if (s[a] >= '0' && s[a] <= '9' && a >= 1)
            {
                p[b] = s[a];
                b++;
            }
        }
        p[b] = 'e';
        if (cou >= 10)
        {
            p[b + 1] = cou / 10 + '0';
            p[b + 2] = cou % 10 + '0';
        }
        else
            p[b + 1] = cou + '0';
        puts(p);
        return 0;
    }
    if (s[9] == '9')
    {
        puts(zhengshu);
        return 0;
    }
    if (s[0] == '0')
    {
        for (c = 2; c < strlen(s); c++)
        {
            if (s[c] == '0')
            {
                flag++;
            }
            else
            {
                break;
            }
        }
        if (strlen(s) <= 3)
        {
            p[0] = s[c];
            p[1] = 'e';
            p[2] = '-';
            p[3] = '1';
            puts(p);
            return 0;
        }
        else
        {
            p[0] = s[c];
            p[1] = '.';
            for (c = c + 1, d = 2; c < strlen(s); c++)
            {
                if (s[c] >= '0' && s[c] <= '9')
                {
                    p[d] = s[c];
                }
            }
            p[d + 1] = 'e';
            p[d + 2] = '-';
            d = d + 2;
            if (flag >= 10)
            {
                p[d + 1] = flag / 10 + '0';
                p[d + 2] = flag % 10 + '0';
            }
            else
                p[d + 1] = flag + '0';
            puts(p);
            return 0;
        }
    }
}

