#include <stdio.h>
#include <string.h>

#define MAXN 110
int n, m, g[MAXN][MAXN];
int vis[MAXN], seq[MAXN];
int cnt;
int que[MAXN], front, rear;
void init()
{
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    front = rear = 0;
    vis[0] = 1;
    seq[cnt++] = 0;
}
void dfs(int u)
{
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || !g[u][i])
        {
            continue;
        }
        vis[i] = 1;
        seq[cnt++] = i;
        dfs(i);
    }
}

void bfs()
{
    que[rear++] = 0;
    while (front <= rear)
    {
        int u = que[front++];
        for (int i = 0; i < n; i++)
        {
            if (vis[i] || !g[u][i])
            {
                continue;
            }
            vis[i] = 1;
            seq[cnt++] = i;
            que[rear++] = i;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    
    init();
    dfs(0);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d%c", seq[i], i == cnt - 1 ? '\n' : ' ');
    }
    
    init();
    bfs();
    for (int i = 0; i < cnt; i++)
    {
        printf("%d%c", seq[i], i == cnt - 1 ? '\n' : ' ');
    }

    int del;
    scanf("%d", &del);
    for (int i = 0; i < n; i++)
    {
        g[i][del] = 0;
        g[del][i] = 0;
    }

    init();
    dfs(0);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d%c", seq[i], i == cnt - 1 ? '\n' : ' ');
    }

    init();
    bfs();
    for (int i = 0; i < cnt; i++)
    {
        printf("%d%c", seq[i], i == cnt - 1 ? '\n' : ' ');
    }
    return 0;
}
