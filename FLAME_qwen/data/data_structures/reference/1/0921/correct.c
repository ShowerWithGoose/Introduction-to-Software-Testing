#include <stdio.h>
#include <string.h>
int n, ans[11], used[11];
void dfs(int);
int main()
{
    memset(used, 4, 0);
    scanf("%d", &n);
    dfs(1);

    return 0;
}
void dfs(int x)
{
    if (x > n)
    {
        for (int k = 1; k <= n; k++)
        {
            printf("% 1d", ans[k]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i] != 1)
        {
            ans[x] = i;
            used[i] = 1;
            dfs(x + 1);
            used[i] = 0;
        }
    }
}
