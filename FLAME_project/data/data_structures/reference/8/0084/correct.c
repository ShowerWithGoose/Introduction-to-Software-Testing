#include<stdio.h>
int visited[105]={0},path[105],level=0,queue[105],front=0,tail=0,vertex[105];
void dfs(int graph[][105],int v,int vn)
{
    int i;
    path[level]=vertex[v];
    level++;
    visited[v]=1;
    for(i=0;i<vn;i++)
    {
        if(graph[v][i]==1&&visited[i]==0)
            dfs(graph,i,vn);
    }
}
void bfs(int graph[][105],int vn)
{
    int a,i;
    while(front<=tail)
    {
        a=queue[front];
        path[level++]=vertex[a];
        visited[a]=1;
        front++;
        for(i=0;i<vn;i++)
        {
            if(graph[a][i]==1&&visited[i]==0)
            {
                tail++;
                queue[tail]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int vn,en,i,j,v1,v2,x;
    int graph[105][105]={0};
    scanf("%d %d",&vn,&en);
    for(i=1;i<=en;i++)
    {
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    scanf("%d",&x);
    for(i=0;i<vn;i++)
    {
        vertex[i]=i;
    }
    for(i=0;i<vn;i++)
    {
        if(visited[i]==0)
            dfs(graph,i,vn);
    }
    for(i=0;i<vn;i++)
    {
        if(i==vn-1)
            printf("%d\n",path[i]);
        else
            printf("%d ",path[i]);
    }
    level=0;
    queue[0]=0;
    for(i=0;i<vn;i++)
        visited[i]=0;
    bfs(graph,vn);
    for(i=0;i<vn;i++)
    {
        if(i==vn-1)
            printf("%d\n",path[i]);
        else
            printf("%d ",path[i]);
    }
    for(i=x+1;i<vn;i++)
    {
        vertex[i-1]=vertex[i];
    }
    for(i=0;i<vn;i++)
    {
        for(j=x+1;j<vn;j++)
        {
            graph[i][j-1]=graph[i][j];
        }
    }
    for(i=0;i<vn-1;i++)
    {
        for(j=x+1;j<vn;j++)
        {
            graph[j-1][i]=graph[j][i];
        }
    }
    vn--;
    level=0;
    for(i=0;i<vn;i++)
        visited[i]=0;
    for(i=0;i<vn;i++)
    {
        if(visited[i]==0)
            dfs(graph,i,vn);
    }
    for(i=0;i<vn;i++)
    {
        if(i==vn-1)
            printf("%d\n",path[i]);
        else
            printf("%d ",path[i]);
    }
    level=0;
    queue[0]=0;
    front=tail=0;
    for(i=0;i<vn;i++)
        visited[i]=0;
    bfs(graph,vn);
    for(i=0;i<vn;i++)
    {
        if(i==vn-1)
            printf("%d\n",path[i]);
        else
            printf("%d ",path[i]);
    }
    return 0;
}

