#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int e[10000][10000];
int st[10000];
int sum1;
int n,m;
void dfs(int u)
{
    printf("%d ",u);
    st[u]=1;
    for(int i=0;i<n;i++) 
    {
        if(!st[i]&&e[u][i])
        {
        st[i]=1;
        dfs(i);
        }    
    }
}
int queue[100000];
int top=0;
int tail=0;
int std[10000];
void bfs(int u)
{
    queue[tail++]=u;
    std[u]=1;
    while(tail>top)
    {
        int t=queue[top];
        printf("%d ",t);
        top++;
        for(int i=0;i<n;i++)
        {
            if(!std[i]&&e[t][i])
            {    queue[tail++]=i;
                std[i]=1;
            }
        }
    }
}
int main()
{
    memset(e,0,sizeof(int)); // @@ [Incorrect use of sizeof: should be sizeof(e) to zero out the entire adjacency matrix, not just one int]
    memset(st,0,sizeof(int)); // @@ [Incorrect use of sizeof: should be sizeof(st) to zero out the entire visited array]
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    int re;scanf("%d",&re);
    for(int i=0;i<n;i++)
    {
        if(!st[i]) dfs(i); // @@ [DFS should start only from vertex 0, not from every unvisited vertex; violates problem requirement]
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ [Incorrect use of sizeof: should be sizeof(std)]
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);    // @@ [BFS should start only from vertex 0, not from every unvisited vertex; violates problem requirement]
        }
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
        e[i][re]=0;
        e[re][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        st[i]=std[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!st[i]) dfs(i); // @@ [After deletion, DFS should start only from vertex 0, not from every unvisited vertex]
    }
    printf("\n");
        
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);    // @@ [After deletion, BFS should start only from vertex 0, not from every unvisited vertex]
        }
    }
    return 0;
}