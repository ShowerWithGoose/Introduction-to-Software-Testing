#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 110

int map[maxn][maxn];
int vis[maxn];
int queue[maxn * maxn], tail, head;
int n, m;

void dfs(int now)
{
    vis[now] = 1;
    printf("%d ", now);
    for(int i = 0; i < n; ++i)
        if(!vis[i] && map[now][i])
            dfs(i);
    return;
}

void bfs(int begin)
{
    tail = head = 0;
    queue[tail++] = begin;
    vis[begin] = 1;
    while(tail != head)
    {
        int now = queue[head++];
        printf("%d ", now);
        for(int i = 0; i < n; ++i)
            if(!vis[i] && map[now][i])
            {
                vis[i] = 1;
                queue[tail++] = i;
            }
    }
}

int main()
{
#ifdef DBG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    int x, y;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = map[y][x] = 1;
    }
    int d;
    scanf("%d", &d);
    memset(vis, 0, sizeof(vis));
    dfs(0); printf("\n");
    memset(vis, 0, sizeof(vis));
    bfs(0); printf("\n");
    memset(vis, 0, sizeof(vis));
    vis[d] = 1; dfs(0); printf("\n");
    memset(vis, 0, sizeof(vis));
    vis[d] = 1; bfs(0); printf("\n");
    return 0;
}
