#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100005 // @@ [The array size N=100005 is too large for a 2D array map[N][N] on the stack or in global memory in some environments, causing relocation errors during linking due to excessive static memory usage. The problem states n ≤ 100, so N should be around 107, not 100005.]
int n,m,del; 
int map[N][N],flag[N]; // @@ [Declaring map[N][N] with N=100005 leads to ~40GB of memory (100005*100005*4 bytes), which is impossible and causes linker relocation truncation errors.]
void dfs(int id)
{
    printf("%d ",id);flag[id]=1;
    for(int i=0;i<n;i++)
        if(map[id][i]&&!flag[i])dfs(i);
}
void bfs(int id)
{
    int queue[N],head,tail=-1; // @@ [queue[N] with N=100005 is unnecessarily large but acceptable alone; however, combined with the huge map, it contributes to overall memory bloat.]
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