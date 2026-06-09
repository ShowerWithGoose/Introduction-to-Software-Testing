#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,m;
int e[200][200];
int vis[200];
int hd,tl,qu[200];

void dfs(int now)
{
    vis[now]=1;
    printf("%d ",now);
    for(int i=0;i<n;i++)
    {
        if(e[now][i]==1&&vis[i]!=1) dfs(i);
    }
    return;
}

void bfs(int now)
{
    hd=1;tl=1;
    qu[tl]=now;
    vis[now]=1;
    while(hd<=tl)
    {
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1&&e[qu[hd]][i]==1)
            {
                vis[i]=1;
                qu[++tl]=i;
            }
        }

        hd++;
    }
    for(int i=1;i<=tl;i++) printf("%d ",qu[i]);
    return;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u][v]=1;e[v][u]=1;
    }
    dfs(0);puts(" ");
    memset(vis,0,sizeof(vis));
    bfs(0);
    puts(" ");
    int u;
    scanf("%d",&u);
    for(int i=0;i<n;i++) 
    {
        e[i][u]=0;
        e[u][i]=0;
    }
    memset(vis,0,sizeof(vis));
    dfs(0);puts(" ");
    memset(vis,0,sizeof(vis));
    bfs(0);
    return 0;
}
