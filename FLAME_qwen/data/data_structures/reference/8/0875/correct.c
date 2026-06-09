#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int graph[200][200];
int n,tou=0;
int visited[200];
int queue[200];
int y=0;
void creatGraph(int m);
void DFS(int x);
void BFS(int x);
int main()
{
    int m,del;
    scanf("%d%d",&n,&m);
    creatGraph(m);
    scanf("%d",&del);
    DFS(0);
    printf("\n");
    for (int i = 0; i < 200; ++i)visited[i]=0;
    BFS(0);
    printf("\n");
    for (int i = 0; i < 200; ++i)visited[i]=0;
    for (int i = 0; i < n; ++i)
    {
        graph[del][i]=0;
        graph[i][del]=0;
    }
    DFS(0);
    printf("\n");
    for (int i = 0; i < 200; ++i)visited[i]=0;
    BFS(0);
    //printf("\n");
    for (int i = 0; i < 200; ++i)visited[i]=0;
    return 0;
}
void DFS(int x)
{
    printf("%d ",x);
    visited[x]=1;
    for (int i = 0; i <n ; ++i)
    {
        if(graph[x][i]==1&&visited[i]==0)DFS(i);
    }
    return;
}
void BFS(int x)
{
    visited[x]=1;
    if(x==0)printf("%d ",x);
    for (int i = 0; i < n; ++i)
    {
        if(graph[x][i]==1&&visited[i]==0)
        {
            printf("%d ",i);
            queue[y++]=i;
            visited[i]=1;
        }
    }
    for (; tou<y;)
    {
        BFS(queue[tou++]);
    }
    return;
}
void creatGraph(int m)
{
    int a,b;
    while (m--)
    {
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    return;
}



