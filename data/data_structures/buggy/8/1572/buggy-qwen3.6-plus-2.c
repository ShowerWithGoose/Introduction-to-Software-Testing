#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 105 // @@ The original value 100005 is excessively large, causing compilation errors or memory limit exceeded. Since n <= 100, N should be around 105.
int n,m,del; 
int map[N][N],flag[N];
void dfs(int id)
{
    printf("%d ",id);flag[id]=1;
    for(int i=0;i<n;i++)
        if(map[id][i]&&!flag[i])dfs(i);
}
void bfs(int id)
{
    int queue[N],head=0,tail=-1; // @@ Variable 'head' is uninitialized, leading to undefined behavior in the while loop condition. It must be initialized to 0.
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