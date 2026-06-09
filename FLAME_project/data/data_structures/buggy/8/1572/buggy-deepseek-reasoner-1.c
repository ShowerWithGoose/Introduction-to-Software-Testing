#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100005 @@ // [Array size too large (100005) causes memory allocation failure and linker relocation errors; should be at most 100 to match constraints.]
int n,m,del; 
int map[N][N],flag[N]; @@ // [Both arrays are oversized due to large N, leading to compilation/link errors; reduce N or allocate dynamically]
void dfs(int id)
{
    printf("%d ",id);flag[id]=1;
    for(int i=0;i<n;i++)
        if(map[id][i]&&!flag[i])dfs(i);
}
void bfs(int id)
{
    int queue[N],head,tail=-1; @@ // [head uninitialized; queue size too large (N=100005), should be small like n]
    queue[++tail]=id;flag[id]=1;
    while(head<=tail)
    {
        id=queue[head++];printf("%d ",id);
        for(int i=0;i<n;i++)
            if(map[id][i]&&!flag[i])
            {
                queue[++tail]=i;
                flag[i]=1;
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        map[u][v]=1;map[v][u]=1;
    }
    scanf("%d",&del);
    dfs(0);printf("\n");
    for(int i=0;i<n;i++)flag[i]=0;
    bfs(0);printf("\n");
    for(int i=0;i<n;i++)
    {
        map[del][i]=0;
        map[i][del]=0;
    }
    for(int i=0;i<n;i++)flag[i]=0;
    dfs(0);printf("\n");
    for(int i=0;i<n;i++)flag[i]=0;
    bfs(0);printf("\n");
    return 0;
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/