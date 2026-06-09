#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int graph[100][100]= {0},visited[100]= {0};
void DFS(int n,int v);
void BFS(int n,int v);
int main()
{
    int i,j,n,num,v1,v2,v;
    scanf("%d%d",&n,&num);
    for(i=0; i<num; i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    DFS(n,0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    BFS(n,0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    scanf("%d",&v);
    for(i=0;i<num;i++)
    {
        graph[i][v]=0;
        graph[v][i]=0;
    }

    DFS(n,0);
    printf("\n");
    memset(visited,0,sizeof(visited));

    BFS(n,0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    return 0;
}

void DFS(int n,int v)
{
    int i;
    printf("%d ",v);
    visited[v]=1;
    for(i=0; i<n; i++)
    {
        if(graph[v][i]==1&&visited[i]==0)
        {
            DFS(n,i);
        }
    }
}

void BFS(int n,int v)
{
    int i,front=0,rear=1,key,queen[100]={0};
    queen[front]=v;
    while(front<=rear)
    {
        key=queen[front++];
        if(visited[key]==0)
        {
            printf("%d ",key);
            visited[key]=1;
            for(i=0; i<n; i++)
            {
                if(graph[key][i]==1&&visited[i]==0)
                {
                    queen[rear++]=i;
                }
            }
        }
    }
}

