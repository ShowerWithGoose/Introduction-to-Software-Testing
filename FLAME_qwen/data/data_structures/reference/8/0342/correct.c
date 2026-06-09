/*
 * @Author:
 * @Date: 2022-05-26 19:17:05
 * @LastEditors:
 * @LastEditTime: 2022-05-26 19:25:57
 * @FilePath: graphSearch.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 110
int n,m,del,head,tail;
int A[MAXN][MAXN];
int vis[MAXN],q[10010];

void dfs(int u)
{
    vis[u] = 1;
    printf("%d ",u);
    for(int v=0;v<n;++v)
    if(!vis[v])
    if(A[u][v])
        dfs(v);
}
void bfs(int u)
{
    head = 0;tail = 0;
    q[tail++] = u;
    vis[u] = 1;
    while(head < tail)
    {
        u = q[head]; ++head;
        printf("%d ",u);
        for(int v=0;v<n;++v)
        if(!vis[v])
        if(A[u][v])
        {
            vis[v] = 1;
            q[tail++] = v;
        }
    }
    return;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        A[u][v] = A[v][u] = 1;
    }
    dfs(0); memset(vis,0,sizeof(vis)); putchar('\n');
    bfs(0); memset(vis,0,sizeof(vis)); putchar('\n');
    scanf("%d",&del);
    for(int i=0;i<n;++i) A[i][del] = 0;
    dfs(0); memset(vis,0,sizeof(vis)); putchar('\n');
    bfs(0); memset(vis,0,sizeof(vis)); putchar('\n');
    return 0;
}
