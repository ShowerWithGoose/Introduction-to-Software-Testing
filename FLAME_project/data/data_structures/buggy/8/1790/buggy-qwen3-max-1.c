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
    } // @@ [This debug printout of the adjacency matrix is not part of the required output and causes extra lines in the output, leading to wrong answer.]
    scanf("%d",&drop_v);
    for(i=0;i<V;i++)
        flag[i]=1;
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1;
    bfs();
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1;
    flag[drop_v]=0; // @@ [Setting flag[drop_v]=0 before traversal prevents visiting the deleted vertex, but the graph structure itself is not updated—edges to drop_v are still present, which may cause incorrect traversal behavior if not handled in adjacency checks. However, the real issue is that the deletion should remove edges, not just mark the vertex as unvisitable. But more critically, the logic of flag initialization is inverted: 1 means "not visited", which is confusing and error-prone.]
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1;
    flag[drop_v]=0; // @@ [Same issue as above: relying on flag to skip deleted vertex instead of actually removing its edges from the graph. Also, the BFS and DFS use flag==1 to mean "not visited", which is opposite of conventional usage and leads to confusion.]
    bfs();
    printf("\n");
    return 0;
} 

void dfs(int n)
{
    int i;
    printf("%d ",n);
    flag[n]=0;
    for(i=0;i<V;i++)
    {
        if(vertex[n][i]==1&&flag[i]==1)
            dfs(i);
    }
}
void bfs()
{
    int queue[100]={0};
    int front=0,rear=0;
    int i;
    queue[rear++]=0;
    printf("0 "); // @@ [Hardcoding "0 " here assumes the first printed vertex is always 0, but it duplicates the logic of printing and skips using the queue value. More importantly, if the starting vertex were different (though it's always 0 per problem), this would break. But the bigger issue is consistency: it prints "0 " before setting flag[0]=0, but what if 0 is the deleted vertex? (It isn't per problem, so maybe okay.) However, combined with the debug printout, this contributes to wrong output format.]
    flag[0]=0;
    while(front!=rear)
    {
        for(i=0;i<V;i++)
        {
            if(vertex[queue[front]][i]==1&&flag[i]==1)
            {
                queue[rear++]=i;
                printf("%d ",i);
                flag[i]=0;
            }
        }
        front++;
    }
}