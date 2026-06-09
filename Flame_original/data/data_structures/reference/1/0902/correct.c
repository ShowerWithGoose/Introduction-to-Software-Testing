#include <stdio.h>
#include <string.h>
#include <ctype.h>

int a[20], b[20];

void dfs(int n, int depth)
{
    if (depth == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        if (!b[i])
        {
            b[i] = 1;
            a[depth] = i;
            dfs(n, depth + 1);
            b[i] = 0;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    dfs(n, 1);
    return 0;
}
