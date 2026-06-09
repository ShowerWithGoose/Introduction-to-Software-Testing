#include<stdio.h>
int graph[107][107] = {0};
int visited[107] = {0};
int nDot,nLine,head = 0,rear = -1;
int queue[107];
void push(int x)
{
    queue[++rear] = x;
}
void pop(int x)
{
    head++;
}
void DFS(int start)
{
    int i;
    printf("%d ",start);
    visited[start] = 1;
    for(i = 0;i < nDot;i++)
    {
       if(graph[start][i] == 1 && visited[i] == 0)
       {
            DFS(i);    
       }
    }
}
void BFS(int start)
{
    int i;
    push(start);
    printf("%d ",start);
    visited[start] = 1;//push print visit 看作一个步骤
    while(rear >= head)
    {
        start = queue[head];
        pop(head);
        for(i = 0;i < nDot; i++)
        {
            if(graph[start][i] == 1 && visited[i] == 0)
            {
                push(i);
                printf("%d ",i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int i,u,v,de;
    scanf("%d %d",&nDot,&nLine);
    for(i = 0;i < nLine;i++)
    {
        scanf("%d %d",&u,&v);
        graph[u][v] = graph[v][u] = 1;
    }
    scanf("%d",&de);
    DFS(0);
    printf("\n");
    for(i = 0;i < nDot;i++)  visited[i] = 0;
    BFS(0);
    printf("\n");
    for(i = 0;i < nDot ;i++)
    {
        graph[de][i] = graph[i][de] = 0;
    }
    for(i = 0;i < nDot;i++)  visited[i] = 0;
    DFS(0);
    printf("\n");
    for(i = 0;i < nDot;i++)  visited[i] = 0;
    BFS(0);
    printf("\n");
    return 0;
}
