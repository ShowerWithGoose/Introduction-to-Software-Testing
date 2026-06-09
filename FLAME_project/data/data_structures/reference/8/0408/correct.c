#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int getEdge(int *connectmap,int size,int node, int num)
{
    int edge=node;
    for (int i = 0; i < size&&num; i++)
    {
        int *loc=( i<node ? connectmap+i*size+node : connectmap+node*size+i );
        if((*loc)==1) num--, edge=i;
    }
    if(num) return -1;
    else return edge;
}

//BFS Function starts===========================================

void BFS_visit(int node,int visited[])
{
    printf("%d ",node);
}

void BFS_dive(int *connectmap,int size,int qsize,int node,int visited[])
{
    int queue[qsize], qfront=0, qback=0;
    queue[qback++]=node, visited[node]=1;
    while (qfront<qsize)
    {
        int current=queue[qfront++], next=current, cnt=1;
        BFS_visit(current,visited);
        while ((next=getEdge(connectmap,size,current,cnt++))!=-1)
        {
            if(visited[next]==0)
            queue[qback++]=next, visited[next]=1;
        }    
    }
}

void BFS(int *bin, int size, int from, int del)
{
    int visited[size], qsize=(del==-1 ? size : size-1 );
    memset(visited,0,sizeof(visited));
    for (int i = 0; i < size; i++)
    {
        if(!visited[i] && i!=del)
        BFS_dive(bin,size,qsize,i,visited);
    }
}

//BFS Function ends=============================================
//DFS Function start============================================

void DFS_visit(int node,int visited[])
{
    visited[node]=1;
    printf("%d ",node);
}

void DFS_dive(int *connectmap,int size,int node,int visited[])
{
    DFS_visit(node,visited);
    int next=node, cnt=0;
    while ((next=getEdge(connectmap,size,node,cnt++))!=-1)
    {
        if(visited[next]==0)
        DFS_dive(connectmap,size,next,visited);    
    }
}

void DFS(int *bin, int size, int from, int del)
{
    int visited[size];
    memset(visited,0,sizeof(visited));
    for (int i = 0; i < size; i++)
    {
        if(!visited[i] && i!=del)
        DFS_dive(bin,size,i,visited);
    }
}

//DFS function ends=============================================

int main ()
{
    int nodeNum=0, edgeNum=0;
    scanf("%d%d",&nodeNum,&edgeNum);

    int map_connect[nodeNum][nodeNum];
    memset(map_connect,0,sizeof(map_connect));

    for (int i = 0; i < edgeNum; i++)
    {
        int x=0,y=0;
        scanf("%d%d",&x,&y);

        if(x<y)
        {
            map_connect[x][y]=1;
        }
        else
        {
            map_connect[y][x]=1;
        }
    }

    DFS((int*)map_connect,nodeNum,0,-1); printf("\n");
    BFS((int*)map_connect,nodeNum,0,-1); printf("\n");

    int del=-1;
    scanf("%d",&del);
    for (int i = 0; i < nodeNum; i++)
    {
        if(i==del) continue;
        else if(i>del)  map_connect[del][i]=0;
        else            map_connect[i][del]=0;
    }

    
    DFS((int*)map_connect,nodeNum,0,del); printf("\n");
    BFS((int*)map_connect,nodeNum,0,del);
    return 0;
}



