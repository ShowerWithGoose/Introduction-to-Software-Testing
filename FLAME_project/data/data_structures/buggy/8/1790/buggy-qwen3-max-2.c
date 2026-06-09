#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int vertex[100][100]={0};
int flag[100]={0};
int V,E,v1,v2,drop_v;

void dfs(int n);
void bfs();

int main()
{
    int i,j;
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++)
    {
        scanf("%d%d",&v1,&v2);
        vertex[v1][v2]=1;
        vertex[v2][v1]=1;
    }
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf("%d ",vertex[i][j]);
        printf("\n");
    } // @@ [This debug printout of the adjacency matrix is not part of the required output and causes extra lines in the output, leading to wrong answer]
    scanf("%d",&drop_v);
    for(i=0;i<V;i++)
        flag[i]=1; // @@ [Flag initialization is inverted: 1 means unvisited, but standard convention (and logic in dfs/bfs) expects 0 as unvisited. This leads to incorrect traversal behavior.]
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1; // @@ [Same inversion error: flag should be 0 for unvisited nodes]
    bfs();
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1; // @@ [Again, flag initialization uses 1 for unvisited, which contradicts typical DFS/BFS logic and causes incorrect skipping of nodes]
    flag[drop_v]=0; // @@ [Setting drop_v to 0 (visited) prevents it from being traversed, but since the graph after deletion should exclude this vertex entirely, this approach may work only if traversal never tries to go through it. However, combined with the inverted flag logic, this is error-prone. Also, edges to drop_v are not removed from the adjacency matrix, so the graph still contains connections to drop_v, which violates the problem requirement of deleting the vertex.]
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1; // @@ [Same flag inversion issue]
    flag[drop_v]=0; // @@ [Same issue: edges to drop_v are not removed from the adjacency matrix, so BFS may still consider edges to drop_v even though it's marked as visited. But since the graph structure wasn't updated, this is logically incorrect.]
    bfs();
    printf("\n");
    return 0;
} 

void dfs(int n)
{
    int i;
    printf("%d ",n);
    flag[n]=0; // @@ [Because flag uses inverted logic (1 = unvisited, 0 = visited), this marks node as visited. However, this unconventional approach is fragile and error-prone, especially when combined with missing graph modification (edges to drop_v not removed).]
    for(i=0;i<V;i++)
    {
        if(vertex[n][i]==1&&flag[i]==1) // @@ [This condition relies on the inverted flag logic. While internally consistent, it fails because the adjacency matrix still includes edges to the deleted vertex, so the traversal may attempt to go through drop_v if not for flag[drop_v]=0. However, the real issue is that the graph itself was not modified to remove the vertex.]
            dfs(i);
    }
}
void bfs()
{
    int queue[100]={0};
    int front=0,rear=0;
    int i;
    queue[rear++]=0;
    printf("0 "); // @@ [Hardcoded "0 " breaks if the first printed node isn't 0 (though it always is per problem), but more importantly, it duplicates the print logic and doesn't use a general approach like dfs does. Also, if flag[0] was already 0 (visited), this would be inconsistent, but due to inverted logic, it's set correctly here.]
    flag[0]=0; // @@ [Inverted flag logic again]
    while(front!=rear)
    {
        for(i=0;i<V;i++)
        {
            if(vertex[queue[front]][i]==1&&flag[i]==1) // @@ [Same issue: adjacency matrix still contains edges to drop_v, so if drop_v weren't marked as visited, it would be traversed. But since we mark it visited before traversal, it's skipped. However, the correct approach is to remove edges to drop_v from the graph, not just mark it visited. Also, the inverted flag logic makes the code hard to reason about.]
            {
                queue[rear++]=i;
                printf("%d ",i);
                flag[i]=0; // @@ [Inverted flag assignment]
            }
        }
        front++;
    }
}