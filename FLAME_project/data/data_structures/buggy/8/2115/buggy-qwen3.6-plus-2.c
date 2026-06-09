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
    memset(e,0,sizeof(int)); // @@ [Incorrect size argument for memset, should be sizeof(e), but this likely doesn't cause the WA directly compared to logic errors. However, strictly speaking, it only clears the first few bytes.]
    memset(st,0,sizeof(int)); // @@ [Incorrect size argument for memset, should be sizeof(st). Only clears the first few bytes of the array.]
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
        if(!st[i]) dfs(i); // @@ [The problem requires starting traversal from vertex 0. This loop starts from the lowest unvisited vertex, which is correct for general connected components but the problem specifies starting at 0. Since the graph is connected, starting at 0 is sufficient. More importantly, the output format expects a single line per traversal. This loop structure is okay for connected graphs if we assume connectivity, but let's look at the next part.]
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ [Incorrect size argument for memset, should be sizeof(std).]
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);    // @@ [Similar to DFS, BFS should start from vertex 0 as per problem description. Also, the problem states the graph is connected, so one call starting at 0 is enough. Using a loop here is technically safe for connectivity but violates the specific "start from 0" instruction if interpreted strictly as the entry point. However, the major issue is below.]
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
        if(!st[i]) dfs(i); // @@ [After deleting vertex 're', the code does not mark 're' as visited. The DFS function will still try to visit 're' if it encounters it in the adjacency loop (though edges are removed, so it won't traverse TO it). However, if the loop index 'i' reaches 're', and 'st[re]' is 0, it will call dfs(re). The problem says we delete the vertex, so it should not appear in the output. By not marking st[re]=1 before this loop, if the graph logic allows or if the loop hits 're', it might print it or cause issues. Specifically, since edges to 're' are removed, dfs(re) would just print 're' and return. This results in 're' appearing in the output sequence, which is wrong. We must mark vis[re]=1 or skip it.]
    }
    printf("\n");
        
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);    // @@ [Same error as above. The deleted vertex 're' is not marked as visited in 'std'. If the loop reaches i==re, bfs(re) will be called, printing 're' into the output. This causes the Wrong Answer.]
        }
    }
    return 0;
}