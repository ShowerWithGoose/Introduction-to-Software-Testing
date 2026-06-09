#include<stdio.h>
#include<stdlib.h>
int del=-1;
int pointnum,sidenum;
int G[500][500];
void DFS(int v,int visited[])
{
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<pointnum;i++)
    {
        if(!visited[i]&&G[v][i]) DFS(i,visited);
    }
}
void deeptrave()
{
    int visited[500];
    for(int i=0;i<pointnum;i++)
    {
        if(i==del) visited[i]=1;
        else visited[i]=0;
    } 
    for(int i=0;i<pointnum;i++)
    {
        if(!visited[i]) DFS(i,visited);
    }
    printf("\n");
}
void BFS(int v,int visted[],int quene[])
{
    int t;
    int front=0,rear=1;
    quene[front]=v;
    while(front<=rear)
    {
        t=quene[front++];
        if(visted[t]) continue;
        else{
            printf("%d ",t);
            visted[t]=1;
            for(int i=0;i<pointnum;i++)
            {
            if(!visted[i]&&G[t][i])
            {
                quene[rear++]=i;
            }
            }
        }
    }   
}
void widetrave()
{
    int visted[500]={},quene[500]={};
    for(int i=0;i<pointnum;i++)
    {
        if(i==del) visted[i]=1;
        else visted[i]=0;
    } 
    BFS(0,visted,quene);
    printf("\n");
}
int main()
{
    scanf("%d %d",&pointnum,&sidenum);
    for(int i=0;i<sidenum;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        G[v1][v2]=1;
        G[v2][v1]=1;
    }
    deeptrave();
    widetrave();
    scanf("%d",&del);
    deeptrave();
    widetrave();
}
