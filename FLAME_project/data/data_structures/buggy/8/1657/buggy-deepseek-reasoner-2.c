#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int e[101][101],num[101],vis[101],queue[101],f=0,l=-1;
void dfs(int i)
{
    printf("%d ",i);
    vis[i]=1;
    for(int j=0;j<num[i];++j)
        if(!vis[e[i][j]]) dfs(e[i][j]);
}
void bfs()
{
    queue[++l]=0;
    while(l>=f)
    {
        int tmp=queue[f];
        f++;
        if(!vis[tmp])
        {
            printf("%d ",tmp);
            vis[tmp]=1;
            for(int j=0;j<num[tmp];++j)
                if(!vis[e[tmp][j]]) queue[++l]=e[tmp][j];
        }
    }
}
int cmp(const void *a,const void *b)
{
    int *aa=(int *)a;
    int *bb=(int *)b;
    if(*aa>*bb) return 1;
    return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u][num[u]]=v;e[v][num[v]]=u;
        ++num[u],++num[v];
    }
    for(int i=0;i<n;++i)
        qsort(e[i],num[i],sizeof(int),cmp);
    // for(int i=0;i<n;++i)
    // {
    //     for(int j=0;j<num[i];++j)
    //         printf("%d ",e[i][j]);
    //     printf("\n");
    // }
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    bfs(); @@ [Missing newline after BFS output; output concatenates with next line]
    memset(vis,0,sizeof(vis));
    int x;
    scanf("%d",&x);
    vis[x]=1;
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    bfs(); @@ [Missing newline after BFS output; output concatenates with previous line]
    return 0;
}