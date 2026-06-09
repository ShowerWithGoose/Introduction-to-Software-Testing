#include <stdio.h>
#include <string.h>
int G[105][105]={0};
int visited[105]={0};
int n,edge;
int queue[1000],head=0,rear=-1;
int isempty ()
{
    return head > rear;
}
int push(int x)
{
    queue[++rear]=x;
}
int pop()
{
    if(!isempty())
       return queue[head++];
    else
        return -1;
}
void travelDFS(int v)
{
    printf("%d ",v);//访问
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
        if(G[v][i]==1 && !visited[i])
        {
            travelDFS(i);
        }
    }
}
void travelBFS(int v)
{
    push(v);
    printf("%d ",v); //访问
    visited[v]=1;
    while(!isempty())
    {
        int x=pop();
        for(int i=0 ;i < n; i++)
        {
            if(G[x][i] == 1 && !visited[i]){
                push(i);
                printf("%d ",i);
                visited[i]=1;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&edge);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        G[v][u]=1;
    }
    travelDFS(0);
    printf("\n");
    memset(visited,0,105);
    memset(queue,0,1000);

    travelBFS(0);
    printf("\n");
    memset(visited,0,105);
    memset(queue,0,1000);

    int deleted;
    scanf("%d",&deleted);
    visited[deleted]=1;

    travelDFS(0);
    printf("\n");
    memset(visited,0,105);
    memset(queue,0,1000);

    visited[deleted]=1;

    travelBFS(0);
    printf("\n");
    return 0;
}
