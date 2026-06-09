#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void str_rev(int s[], int high, int low)
{
    int temp;
    for (; high > low; low++, high--)
    {
        temp = s[low];
        s[low] = s[high];
        s[high] = temp;
    }
}

int main()
{

    int i, j, n, temp, flag = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        printf("%d", a[i]); // @@ Missing space between integers; should be "%d " to match the required output format
    printf("\n");
    while (flag)
    {
        flag = 0;

        for (i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            break;

        for (j = n; j > 1; j--)
        {
            if (a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                break;
            }
        }

        str_rev(a, n, i + 1);
        for (i = 1; i <= n; i++)
            printf("%d", a[i]); // @@ Missing space between integers; should be "%d " to match the required output format
        printf("\n");
    }

    return 0;
}