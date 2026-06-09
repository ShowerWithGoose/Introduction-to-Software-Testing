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
    for(i=0;i<V;i++) // @@ The loop printing the adjacency matrix is not part of the required output. This produces extra lines.
    {
        for(j=0;j<V;j++) // @@ Printing matrix entries is not required.
            printf("%d ",vertex[i][j]); // @@ Unwanted output of the adjacency matrix.
        printf("\n");
    }
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
    flag[drop_v]=0; // @@ Should also remove all edges incident to drop_v (set vertex[i][drop_v]=0 and vertex[drop_v][i]=0). Marking visited alone is not equivalent to deleting the vertex.
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1;
    flag[drop_v]=0; // @@ Same issue: edges to drop_v should be removed from the adjacency matrix.
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
    printf("0 ");
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