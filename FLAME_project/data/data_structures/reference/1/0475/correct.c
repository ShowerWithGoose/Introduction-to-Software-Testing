#include <stdio.h>
int num[10], N;
void out(int, int *);
int main()
{
    scanf("%d", &N);
    int n = N;
    int i;
    int a[N];
    for (i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    out(n, a);
    return 0;
}
void out(int n, int *b)
{
    int i, j;
    int c[n - 1], temp;
    for (i = 0; i < n; i++)
    {
        num[n - 1] = b[i];
        for (j = 0; j < i; j++)
        {
            c[j] = b[j];
        }
        for (j = i + 1; j < n; j++)
        {
            c[j - 1] = b[j];
        }
        if (n == 1)
        {
            for (j = N - 1; j >= 1; j--)
            {
                printf("%d ", num[j]);
            }
            printf("%d\n", num[j]);
        }
        if (n > 1)
        {
            out(n - 1, c);
        }
    }
}
