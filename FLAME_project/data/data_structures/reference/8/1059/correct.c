#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 102
int mp[N][N];
int n, m, d;
int vis[N], q[N], f, r;

void dfs(int u)
{
    vis[u] = 1;
    printf("%d ", u);
    for(int i = 0; i < n; i++)
        if(!vis[i] && mp[u][i])
            dfs(i);
}

void bfs(int s)
{
    f = r = 0;
    q[r++] = s;
    vis[0] = 1;
    while(f != r)
    {
        int u = q[f++];
        printf("%d ", u);
        for(int i = 0; i < n; i++)
            if(!vis[i] && mp[u][i])
            {
                q[r++] = i;
                vis[i] = 1;
            }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        mp[u][v] = mp[v][u] = 1;
    }
    memset(vis, 0, sizeof vis); dfs(0); putchar('\n');
    memset(vis, 0, sizeof vis); bfs(0); putchar('\n');
    scanf("%d", &d);
    for(int i = 0; i < n; i++)
        mp[i][d] = mp[d][i] = 0;
    memset(vis, 0, sizeof vis); dfs(0); putchar('\n');
    memset(vis, 0, sizeof vis); bfs(0); putchar('\n');
    return 0;
}
