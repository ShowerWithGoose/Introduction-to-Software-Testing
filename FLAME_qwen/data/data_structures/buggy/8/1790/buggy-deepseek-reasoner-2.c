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
    for(i=0;i<V;i++) // @@ [This loop and the following three lines print the adjacency matrix, which is not part of the required output and will cause output mismatch.]
    {
        for(j=0;j<V;j++) // @@ [Same reason: extra output.]
            printf("%d ",vertex[i][j]); // @@ [Prints matrix values, not required.]
        printf("\n"); // @@ [Extra newline from matrix output.]
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
    flag[drop_v]=0;
    dfs(0);
    printf("\n");
    for(i=0;i<V;i++)
        flag[i]=1;
    flag[drop_v]=0;
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