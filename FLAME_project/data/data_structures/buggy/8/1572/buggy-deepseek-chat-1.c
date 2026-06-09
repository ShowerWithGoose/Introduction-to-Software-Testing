#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100005
int n,m,del; 
int map[N][N],flag[N]; // @@ [Error: The array size N is 100005, which is too large for stack allocation. The problem constraints say n ≤ 100, so N should be at most 107. The large array causes relocation errors during linking.]
void dfs(int id)
{
    printf("%d ",id);flag[id]=1;
    for(int i=0;i<n;i++)
        if(map[id][i]&&!flag[i])dfs(i);
}
void bfs(int id)
{
    int queue[N],head,tail=-1; // @@ [Error: queue array size N is 100005, too large for stack allocation. This causes relocation errors.]
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