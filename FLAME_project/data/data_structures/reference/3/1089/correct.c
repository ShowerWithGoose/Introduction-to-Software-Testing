#include <stdio.h>
char a[100] = {'\0'};
int main()
{
    int i = 0, k, n, m, flag = 0, o, p;
    while ((scanf("%c", &a[i])) != EOF)
    {
        if (a[i] == '.')
        {
            flag = 1;
        }
        i++;
    }
    if (a[0] == '0')
    {
        for (k = 2; k <= i - 2; k++)
        {
            if (a[k] != '0' && k == 2 && a[k] != '\n' && a[k] != '.')
            {
                printf("%ce-%d", a[k], i - 4);
            }
            else if (a[k] != '0' && k != 2 && a[k] != '\n' && a[k] != '.')
            {
                printf("%c.", a[k]);
                for (n = k + 1; n <= i - 2; n++)
                {
                    if (a[n] != '\n' && a[k] != '.')
                        printf("%c", a[n]);
                }
                printf("e-%d", k - 1);
                break;
            }
        }
    }
    else if (a[i] == '0' && flag == 1)
    {
        printf("%c.", a[0]);
        for (m = 1; m <= i - 2; m++)
        {
            if (a[m] == '.')
            {
                o = m;
                m++;
                printf("%c", a[m]);
            }
            else if (a[m] != '.' && a[m] != '\n')
                printf("%c", a[m]);
        }
        printf("e%d", o - 1);
    }
    else
    {
        printf("%c.", a[0]);
        for (p = 1; p <= i - 2; p++)
        {
            if (a[p] == '.')
            {
                o = p;
            }
            else if (a[p] == '\n')
            {
                continue;
            }
            if (a[p] != '.' && a[p] != '\n')
                printf("%c", a[p]);
        }
        printf("e%d", o - 1);
    }
    return 0;
}
