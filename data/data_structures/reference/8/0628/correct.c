#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
int del[100], G[100][100], vis[100], n, m;

void dfs(int x)
{
    if (del[x]) return ;
    printf("%d ", x);
    vis[x] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i] && G[x][i])
            dfs(i);
    }
}

void bfs(int x)
{
    memset(vis, 0, sizeof(vis));
    int q[1000], s = 0, t = -1, tmp, i;
    q[++t] = x;
    vis[x] = 1;
    while (s <= t)
    {
        tmp = q[s++];
        printf("%d ", tmp);
        for (i = 0; i < n; ++i)
            if (!del[i]&& !vis[i] && G[tmp][i])
            {
                q[++t] = i;
                vis[i] = 1;
            }
    }
    memset(vis, 0, sizeof(vis));
}

int main()
{
    int tmp;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    dfs(0), puts("");
    bfs(0), puts("");
    while (~scanf("%d", &tmp))
        del[tmp] = 1;
    dfs(0), puts("");
    bfs(0), puts("");
    return 0;
}
