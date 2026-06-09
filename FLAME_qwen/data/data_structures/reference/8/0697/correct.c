#include<stdio.h>

int v[110];
int n,m,p;
int map[110][110];
int q[110],head,tail;
void dfs(int x)
{
    v[x]=1;
    printf("%d ",x);
    for(int i=0;i<n;i++)
    if(map[x][i]&&!v[i])
        dfs(i);
}
void bfs()
{
    head=0;tail=-1;
    q[++tail]=0;
    while(head<=tail)
    {
        int x=q[head++];
        if(v[x])continue;v[x]=1;
        printf("%d ",x);
        for(int i=0;i<n;i++)
        if(map[x][i]&&!v[i])
            q[++tail]=i;
    }
}
signed main()
{
    // freopen("data.in","r",stdin);

    scanf("%d%d",&n,&m);
    int uu,vv;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&uu,&vv);
        map[uu][vv]=map[vv][uu]=1;
    }
    scanf("%d",&p);
    dfs(0);puts("");
    for(int i=0;i<=100;i++)v[i]=0;
    bfs();puts("");
    for(int i=0;i<=100;i++)v[i]=0;
    v[p]=1;
    dfs(0);puts("");
    for(int i=0;i<=100;i++)v[i]=0;
    v[p]=1;
    bfs();puts("");
}
