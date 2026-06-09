#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define N 10001
int g[N][N], vis[N], v, e, del, rt[N], cnt, q[N], hh, tt;
void dfs(int step, int tmp, int num)
{
    vis[0] = 1;
    if(cnt == num - 1)//
    {
        printf("0 ");
        for(int j = 0; j < num - 1; j ++)
        printf("%d ", rt[j]);
        puts("");
        memset(rt, 0, sizeof rt);
        cnt = 0;
    }
    for(int i = 0; i < v; i ++)
    {
        if(!vis[i] && g[tmp][i])
        {
            vis[i] = 1;
            rt[cnt ++] = i;
            dfs(step + 1, i, num);
            //break;
            //vis[tmp][i] = 0;
        }
    }
}
void bfs()
{
    vis[0] = 1;
    while(hh <= tt)
    {
        for(int i = 0; i < v; i ++)
        {
            if(g[i][q[hh]] && !vis[i])
            {
                q[++ tt] = i;
                vis[i] = 1;
            }
        }
        printf("%d ", q[hh ++]);
    }
    puts("");
    hh = tt = 0;
}
int main()
{
    scanf("%d%d", &v, &e);
    for(int i = 0; i < e; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    scanf("%d", &del);
    dfs(0, 0, v);
    memset(vis, 0, sizeof vis);
    bfs();
    memset(vis, 0, sizeof vis);
    vis[del] = 1;
    dfs(0, 0, v - 1);
    memset(vis, 0, sizeof vis);
    vis[del] = 1;
    bfs();
    return 0;
}
