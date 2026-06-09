#include <stdio.h>
char a[1000];
char b[1000];
int main()
{
    int i, j, k;
    int e = 0;
    int num = 0;
    int flag = 0;
    char sign;
    gets(a);
    if (a[0] == '0' && a[1] == '.')
    {
        sign = '-';
        for (i = 2, j = 0; a[i] != '\0'; i++)
        {
            if (a[i] != '0')
                flag = 1;
            if (flag == 0)
                e++;
            if (flag == 1)
            {
                b[j++] = a[i];
                num++;
            }
        }
        e++;
        printf("%c", b[0]);
        if (num > 1)
            putchar('.');
        printf("%s", b + 1);
        printf("e%c%d", sign, e);
    }
    else
    {
        for (i = 0, j = 0; a[i] != '\0'; i++)
        {
            if (a[i] != '.')
                b[j++] = a[i];
            if (a[i] == '.')
            {
                flag = 1;
            }
            if (!flag)
                e++;
            else
                num++;
        }
        printf("%c", b[0]);
        if (num > 0)
            putchar('.');
        printf("%s", b + 1);
        printf("e%d", e - 1);
    }

    getchar();
    return 0;
}
