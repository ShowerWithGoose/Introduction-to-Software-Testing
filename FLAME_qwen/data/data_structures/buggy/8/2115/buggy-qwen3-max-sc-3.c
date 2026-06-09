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
        st[i]=1; // @@ [The vertex 'i' is marked as visited before the recursive call, which prevents other paths from exploring it. In DFS, a node should only be marked as visited when it is first entered, but here it's marked prematurely before the recursive call, which may not be wrong per se, but combined with multiple DFS calls from main (not starting only from 0), it causes incorrect traversal order and multiple starts. However, the primary error is that DFS/BFS are called for every unvisited node in main, violating requirement to start only from vertex 0.]
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
                std[i]=1; // @@ [Similar to DFS, BFS marks nodes as visited when enqueued, which is correct. However, the main issue is that BFS is also called for every unvisited component in main, not just starting from 0.]
            }
        }
    }
}
int main()
{
    memset(e,0,sizeof(int)); // @@ [Incorrect use of sizeof: should be sizeof(e) to zero the entire array. Using sizeof(int) only zeros the first 4 bytes, leaving most of the adjacency matrix uninitialized (garbage values). This leads to undefined behavior when checking e[u][i].]
    memset(st,0,sizeof(int)); // @@ [Same error: should be sizeof(st) to clear the whole array. Only first 4 bytes are cleared.]
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    int re;scanf("%d",&re);
    for(int i=0;i<n;i++) // @@ [Violation of requirement: traversal must start from vertex 0 only. This loop starts DFS from every unvisited vertex, producing a forest traversal instead of a single traversal from 0.]
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ [Should be sizeof(std); only first 4 bytes cleared.]
    for(int i=0;i<n;i++) // @@ [Same violation: BFS should start only from vertex 0, not from every unvisited vertex.]
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
    for(int i=0;i<n;i++) // @@ [Again, DFS after deletion should start only from 0, not from all unvisited vertices. Also, note that vertex 're' is not excluded from being a start point, though it's disconnected. But more critically, the traversal must start at 0.]
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
        
    for(int i=0;i<n;i++) // @@ [Same error: BFS after deletion must start only from 0.]
    {
        if(!std[i]) 
        {
        bfs(i);    
        }
    }
    return 0;
}