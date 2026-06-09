#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void pailie(int m, int n, int a[], int temp[]);
int main()
{
    int a[21], temp[21], n;
    scanf("%d", &n);
    int i;
    
    for (i = 0; i < n; i++) temp[i] = 0;
    pailie(0, n, a, temp);
    return 0;
}
void pailie(int m, int n, int a[], int temp[])
{
    int i;
    if (m >= n)//µ×²ã
    {
        for (i = 0; i < n - 1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[i]);
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (temp[i] == 0)
            {
                temp[i] = 1;
                a[m] = i + 1;
                pailie(m + 1, n, a, temp);
                temp[i] = 0;
            }
        }
    }
}

