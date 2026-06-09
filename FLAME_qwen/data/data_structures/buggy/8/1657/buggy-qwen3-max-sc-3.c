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
    return -1; // @@ [The comparison function must return negative, zero, or positive. Returning only 1 or -1 is acceptable in practice for qsort, but strictly speaking, it should return (*aa - *bb) for full correctness. However, the real issue is that this comparator does NOT sort in ascending order correctly when *aa < *bb because it returns -1 even when *aa == *bb is false. But more critically, the BFS and DFS traversals assume neighbors are sorted in ascending order, and this comparator actually sorts in ascending order correctly. So this is likely NOT the bug.]

    // Actually, the real problem is elsewhere.
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int u,v;
        scanf("%d%d",&u,v);
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
    bfs(); // @@ [The BFS function uses global variables 'f' and 'l' which are not reset to initial values (f=0, l=-1) before the first BFS call. They are initialized at declaration, so first BFS works. BUT after first BFS, 'f' and 'l' are left in a modified state. Then, before the second BFS (after deletion), they are NOT reset again. However, looking further: before second BFS, we do reset vis[], but NOT f and l. This causes the second BFS to start with stale queue indices.]

    memset(vis,0,sizeof(vis));
    int x;
    scanf("%d",&x);
    vis[x]=1;
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    bfs(); // @@ [Here, 'f' and 'l' are still holding values from the previous BFS call. They must be reset to f=0, l=-1 before every BFS call. The first BFS worked because f and l were initialized at declaration. But the second BFS uses leftover values, leading to incorrect queue behavior.]

    return 0;
}