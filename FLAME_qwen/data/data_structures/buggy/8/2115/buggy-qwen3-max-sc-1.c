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
        st[i]=1; // @@ [The vertex 'i' is marked as visited before the recursive DFS call, which prevents proper backtracking and may skip valid paths. It should be marked inside the dfs() call or after the condition check but not before recursion. However, more critically, the traversal must start from 0 only, but this code runs DFS on every unvisited node, violating requirement #3.]
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
    memset(e,0,sizeof(int)); // @@ [Incorrect use of sizeof: should be sizeof(e) to zero-initialize the entire adjacency matrix. Using sizeof(int) only zeros the first few bytes, leaving most of the matrix uninitialized.]
    memset(st,0,sizeof(int)); // @@ [Same issue: should be sizeof(st) to properly initialize the whole array.]
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    int re;scanf("%d",&re);
    for(int i=0;i<n;i++) // @@ [Violation of requirement #3: traversal must start from vertex 0 only. This loop starts DFS from every unvisited vertex, producing incorrect output for connected graphs.]
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ [Should be sizeof(std) for correct initialization.]
    for(int i=0;i<n;i++) // @@ [Same violation: BFS must start only from vertex 0, not from every unvisited vertex.]
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
    for(int i=0;i<n;i++) // @@ [Again, DFS after deletion must start only from 0, not from all unvisited nodes.]
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
        
    for(int i=0;i<n;i++) // @@ [BFS after deletion must start only from 0, not from all unvisited nodes.]
    {
        if(!std[i]) 
        {
        bfs(i);    
        }
    }
    return 0;
}