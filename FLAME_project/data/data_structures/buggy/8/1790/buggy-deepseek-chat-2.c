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
    }
    scanf("%d",&drop_v);
    for(i=0;i<V;i++)
        flag[i]=1; // @@ Error: flag should be initialized to 0 (unvisited), not 1. Using 1 as visited and 0 as unvisited is inconsistent with the rest of the code.
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1; // @@ Error: Same issue as above; flag should be set to 0 for unvisited.
    bfs();
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1; // @@ Error: Same issue; flag should be set to 0 for unvisited.
    flag[drop_v]=0; // @@ Error: This sets the deleted vertex as "visited" (0), but the logic is inverted. It should be set to 0 (unvisited) initially, then set to 1 (visited) to mark it as deleted.
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1; // @@ Error: Same issue; flag should be set to 0 for unvisited.
    flag[drop_v]=0; // @@ Error: Same issue as above.
    bfs();
    printf("\n");
    return 0;
} 

void dfs(int n)
{
    int i;
    printf("%d ",n);
    flag[n]=0; // @@ Error: This sets visited nodes to 0, but the initialization uses 1 for unvisited. The logic is inverted.
    for(i=0;i<V;i++)
    {
        if(vertex[n][i]==1&&flag[i]==1) // @@ Error: Condition checks flag[i]==1 (unvisited), but flag is initialized to 1, so this works, but it's confusing and inconsistent.
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
    flag[0]=0; // @@ Error: Same inverted logic; sets visited to 0.
    while(front!=rear)
    {
        for(i=0;i<V;i++)
        {
            if(vertex[queue[front]][i]==1&&flag[i]==1) // @@ Error: Condition checks flag[i]==1 (unvisited), but flag is initialized to 1.
            {
                queue[rear++]=i;
                printf("%d ",i);
                flag[i]=0; // @@ Error: Sets visited to 0.
            }
        }
        front++;
    }
}