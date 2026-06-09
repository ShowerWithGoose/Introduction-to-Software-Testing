#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int g[110][110],del[110],vis[110],flag;
int n,m;
int q[200],st,en;
void print(int u)
{
    if(flag)
    {
        printf(" ");
    }
    flag++;
    printf("%d",u);
}
void dfs(int u)
{
    if(!vis[u])
    {
        vis[u]=1;
        print(u);
        for(int i=0;i<n;i++)
        {
            if(g[u][i]&&!del[i])
            {
                dfs(i);
            }
        }
    }
}
void bfs()
{
    q[++en]=0;
    while(st<=en){
        int t=q[st++];
        if(vis[t])
        {
            continue;
        }
        vis[t] = 1;
        print(t);
        for(int i=0;i<n;i++){
            if(g[t][i]&&!vis[i]&&!del[i])
            {
                q[++en]=i;
            }
        }
    }
}

void trav()
{
    flag=0;
    memset(vis,0,sizeof(vis));
    dfs(0);
    printf("\n");
    flag=0;
    st=0,en=-1;
    memset(vis,0,sizeof(vis));
    bfs();
    printf("\n");
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u][v]=g[v][u]=1;
    }
    trav();
    int x;
    while(scanf("%d", &x)!=EOF)
    {
        del[x]=1;
    }
    trav();
}
