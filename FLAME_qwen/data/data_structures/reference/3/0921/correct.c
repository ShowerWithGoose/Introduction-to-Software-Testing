#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char a[105];
    int i, j, la, k, t, l;
    gets(a);
    la = strlen(a);
    for (j = 0; j < la; j++)
    {
        if (a[j] == '.')
            break;
    }
    if (j == 1 && a[0] == '0')
    {
        for (i = j + 1; i < la; i++)
        {
            if (a[i] != '0')
                break;
        }
        k = 1 - i;
        printf("%c", a[i]);
        if (i != la - 1)
            printf(".");
        for (t = i + 1; t < la; t++)
        {
            printf("%c", a[t]);
        }
        printf("e%d", k);
    }
    else if (j == 1)
    {
        for (t = 0; t < la; t++)
        {
            printf("%c", a[t]);
        }
        printf("e0");
    }
    else
    {
        for (t = j; t < la - 1; t++)
        {
            a[t] = a[t + 1];
        }
        printf("%c.", a[0]);
        for (t = 1; t < la - 1; t++)
        {
            printf("%c", a[t]);
        }
        l = j - 1;
        printf("e%d", l);
    }
    return 0;
}
