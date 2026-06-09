#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn (1005)
#define maxm (2005)

int a[maxn], n;
int vis[maxn];
void dfs(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        a[cur] = i;
        dfs(cur + 1);
        vis[i] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
}
