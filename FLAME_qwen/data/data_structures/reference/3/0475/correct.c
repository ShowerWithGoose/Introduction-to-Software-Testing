#include <stdio.h>
#include <string.h>
int main()
{
    char a[120], b[120];
    gets(a);
    int i, n = strlen(a);
    int judge, PosPoint, sym, PosNumber;
    for (i = 0; i < n; i++)
    {
        if (a[i] == '.')
        {
            PosPoint = i;
            break;
        }
    }
    if (PosPoint == 1 && a[0] == '0')
    {
        for (i = PosPoint + 1; i < n; i++)
        {
            if (a[i] != '0')
            {
                PosNumber = i;
                break;
            }
        }
        if (PosNumber == n - 1)
        {
            printf("%ce-%d", a[PosNumber], PosNumber - PosPoint);
        }
        else
        {
            printf("%c.", a[PosNumber]);
            for (i = PosNumber + 1; i < n; i++)
            {
                printf("%c", a[i]);
            }
            printf("e-%d", PosNumber - PosPoint);
        }
    }
    else if (PosPoint == 1 && a[0] != '0')
    {
        for (i = 0; i < n; i++)
        {
            printf("%c", a[i]);
        }
        printf("e0");
    }
    else if (PosPoint != 1)
    {
        printf("%c.", a[0]);
        for (i = 1; i < PosPoint; i++)
        {
            printf("%c", a[i]);
        }
        for (i = PosPoint + 1; i < n; i++)
        {
            printf("%c", a[i]);
        }
        printf("e%d", PosPoint - 1);
    }
    return 0;
}
