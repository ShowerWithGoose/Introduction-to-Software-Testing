#include<stdio.h>
#include<stdlib.h>
int m=-1;
int pointnum,linenum;
int line[500][500];
void DFS(int v,int visited[])
{
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<pointnum;i++)
    {
        if(!visited[i]&&line[v][i]) DFS(i,visited);
    }
}
void deeptrave()
{
    int visited[500];
    for(int i=0;i<pointnum;i++)
    {
        if(i==m) visited[i]=1;
        else visited[i]=0;
    } 
    for(int i=0;i<pointnum;i++)
    {
        if(!visited[i]) DFS(i,visited);
    }
    printf("\n");
}
void BFS(int v,int visited[],int quene[])
{
    int current;
    int front=0,rear=1;
    quene[front]=v;
    while(front<=rear)
    {
        current=quene[front++];
        if(visited[current]) continue;
        else{
            printf("%d ",current);
            visited[current]=1;
            for(int i=0;i<pointnum;i++)
            {
            if(!visited[i]&&line[current][i])
            {
                quene[rear++]=i;
            }
            }
        }
    }   
}
void widetrave()
{
    int visited[500]={},quene[500]={};
    for(int i=0;i<pointnum;i++)
    {
        if(i==m) visited[i]=1;
        else visited[i]=0;
    } 
    BFS(0,visited,quene);
    printf("\n");
}
int main()
{
    scanf("%d %d",&pointnum,&linenum);
    for(int i=0;i<linenum;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        line[v1][v2]=1;
        line[v2][v1]=1;
    }
    deeptrave();
    widetrave();
    scanf("%d",&m);
    deeptrave();
    widetrave();
}
