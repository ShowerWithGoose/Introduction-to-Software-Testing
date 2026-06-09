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
    memset(e,0,sizeof(int)); // @@ [Incorrect size argument for memset, should be sizeof(e), but this likely doesn't cause the specific WA here as it zeroes part of the array. However, the logic error below is critical.]
    memset(st,0,sizeof(int)); // @@ [Incorrect size argument for memset, should be sizeof(st).]
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
        if(!st[i]) dfs(i); // @@ [The problem requires starting traversal from vertex 0 specifically, not iterating through all vertices. Although the graph is connected, the requirement "start from vertex 0" implies we should call dfs(0) directly. More importantly, the output format expects a single line per traversal. The current loop structure is technically okay for connected graphs if started at 0, but let's look at the deletion part.]
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ [Incorrect size argument for memset, should be sizeof(std).]
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);     // @@ [Similar to DFS, should start from 0. But the critical error is in the deletion logic and subsequent traversals.]
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
        if(!st[i]) dfs(i); // @@ [After deleting vertex 're', the code does not mark 're' as visited. So if the loop reaches 're', it will try to DFS from 're'. Even if it doesn't reach 're' first, the DFS/BFS functions will still iterate through 're' in their loops because 'e' edges are removed but 're' itself is not marked visited in 'st' or 'std'. The vertex 're' should be marked as visited before starting the traversal to simulate its deletion, or the loops inside dfs/bfs should skip it. Since the edges are removed, 're' becomes isolated. If the traversal starts at 0, it won't reach 're'. However, the outer loop `for(int i=0;i<n;i++)` will eventually hit 're' if it hasn't been visited, and print it. The expected output shows 're' is NOT printed. Thus, 're' must be marked as visited before the traversal starts.]
    }
    printf("\n");
        
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);     // @@ [Same issue: 're' is not marked as visited in 'std', so it might be printed if the outer loop reaches it. Also, BFS should start from 0.]
        }
    }
    return 0;
}