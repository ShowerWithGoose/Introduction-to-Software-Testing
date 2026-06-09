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
    memset(e,0,sizeof(int)); // @@ [Error: sizeof(int) is too small; should be sizeof(e) to clear entire 2D array. Uninitialized entries may cause unexpected behavior.]
    memset(st,0,sizeof(int)); // @@ [Error: sizeof(int) is too small; should be sizeof(st).]
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    int re;scanf("%d",&re);
    for(int i=0;i<n;i++) // @@ [Error: Should start DFS from vertex 0 only, not loop over all vertices. The problem requires traversal to start at 0. Looping includes isolated vertices like the deleted one later.]
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ [Error: sizeof(int) is too small; should be sizeof(std).]
    for(int i=0;i<n;i++) // @@ [Error: Should start BFS from vertex 0 only, not loop over all vertices. Additionally, global top and tail are not reset, causing stale indices.]
    {
        if(!std[i]) 
        {
        bfs(i);    
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
    for(int i=0;i<n;i++) // @@ [Error: Same issue - should start DFS from vertex 0 only. This loop causes the deleted vertex to be visited separately.]
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
        
    for(int i=0;i<n;i++) // @@ [Error: Same as before - should start BFS from vertex 0 only. Also, top and tail are not reset, causing incorrect queue indices.]
    {
        if(!std[i]) 
        {
        bfs(i);    
        }
    }
    return 0;
}