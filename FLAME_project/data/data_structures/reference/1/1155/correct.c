#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int);

int n;
int a[100], b[100];

int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}

void dfs(int x)
{
    int i;
    if (x == n + 1)
    {
        for (i = 1; i < n; i ++)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
        return;
    }
    for (i = 1; i <= n; i ++)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            a[x] = i;
            dfs(x + 1);
            b[i] = 0;
        }
    }
    return;
}

