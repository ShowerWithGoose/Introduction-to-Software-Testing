#include <stdio.h>
int main()
{
    char a[100];
    int i = 0, j, k, l, m;
    while ((scanf("%c", &a[i])) != EOF)
    {
        i++;
    }
    for (j = 0; j < i; j++)
    {
        if (a[j] == '-')
        {
            if (a[j - 1] >= 65 && a[j + 1] <= 90)
            {
                for (k = a[j - 1] + 1; k < a[j + 1]; k++)
                {
                    printf("%c", k);
                }
            }
            else if (a[j - 1] >= 97 && a[j + 1] <= 122)
            {
                for (l = a[j - 1] + 1; l < a[j + 1]; l++)
                {
                    printf("%c", l);
                }
            }
            else if (a[j - 1] >= 48 && a[j + 1] <= 57)
            {
                for (m = a[j - 1] + 1; m < a[j + 1]; m++)
                {
                    printf("%c", m);
                }
            }
            else
                printf("%c", a[j]);
        }
        else
            printf("%c", a[j]);
    }
    return 0;
}
