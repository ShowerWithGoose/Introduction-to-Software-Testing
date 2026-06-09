#include <stdio.h>
#include <stdlib.h>
void Permutation(int m, int n, int a[], int tp[]);
int main()
{
    int a[15], tp[15], n;
    scanf("%d", &n);
    int i;

    for (i = 0; i < n; i++)
        tp[i] = 0;
    Permutation(0, n, a, tp);
    return 0;
}
void Permutation(int m, int n, int a[], int tp[])
{
    int i;

    if(m >= n)
    {
        for (i = 0; i < n-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[i]);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if (tp[i] == 0)
            {
                tp[i] = 1;
                a[m] = i + 1;

                Permutation(m + 1, n, a, tp);

                tp[i] = 0;
            }
        }
    }
}



