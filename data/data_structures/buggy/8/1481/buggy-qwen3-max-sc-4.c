#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max(a,b) (a>b?a:b)
#define MAXSIZE 105

typedef struct edge
{
    int adjvex;
    int weight;
    struct edge *next;
}ELink;

typedef struct ver
{
    ELink *link;
}VLink;
VLink G[MAXSIZE]; 

int Visited[MAXSIZE];//懒惰删除，1为删除或被访问过 
int queue[MAXSIZE];

ELink *insertEdge(ELink *head,int avex);
void createGraph(VLink *graph);//建立无向图 
void DFS(VLink *G,int v);
void travelDFS(VLink *G,int n,int del);//del表示要删除的节点 
void BFS(VLink *G,int v);
void travelBFS(VLink *G,int n,int del);

int main()
{
    int v,n;
    scanf("%d",&v);
    createGraph(G);
    travelDFS(G,v,-1); 
    travelBFS(G,v,-1);
    scanf("%d",&n);
    travelDFS(G,v,n);
    travelBFS(G,v,n);
    return 0;
}

ELink *insertEdge(ELink *head,int avex)
{
    ELink *e=(ELink*)malloc(sizeof(ELink));
    e->adjvex=avex;
    e->weight=1;
    e->next=NULL;
    if(head==NULL)//head是空表 
    {
        head=e;
        return head;
    }
    ELink *p=head,*q=NULL;
    while(p!=NULL&&avex>p->adjvex)//寻找插入位置 
    {
        q=p;
        p=p->next;
    }
    if(p==head)//在头节点插入 
    {
        e->next=p;
        return e;
    }
    else
    {
        q->next=e;
        e->next=p;
        return head;
    }
}
void createGraph(VLink *graph)
{
    int e,v1,v2;
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }
} 

void DFS(VLink *G,int v)
{
    ELink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!Visited[p->adjvex])
        {
            DFS(G,p->adjvex);
        }
    }
}
void travelDFS(VLink *G,int n,int del)
{
    for(int i=0;i<n;i++)
    {
        Visited[i]=0;
    }
    if(del>=0)
    {
        Visited[del]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(!Visited[i])
        {
            DFS(G,i);
        }
    }
    putchar('\n');
}

void BFS(VLink *G,int v)
{
    ELink *p;
    int front=0,rear=-1;
    Visited[v]=1;//顶点被访问 
    queue[++rear]=v;//入队 
    while(rear>=front)//队列不为空 
    {    
        printf("%d ",queue[front++]);//出队 
        for(p=G[v].link;p!=NULL;p=p->next) // @@ [In BFS traversal, after dequeuing a vertex 'queue[front-1]', the adjacency list of that vertex should be traversed, but here it's still using 'G[v].link' where 'v' is the initial starting vertex. This causes incorrect neighbor exploration. It should use 'G[queue[front-1]].link' or store the current vertex in a variable.]
        {
            if(Visited[p->adjvex]==0)//顶点未被访问 
            {
                Visited[p->adjvex]=1;//顶点被访问 
                queue[++rear]=p->adjvex;//入队 
            }
        }
    }
}
void travelBFS(VLink *G,int n,int del)
{
    for(int i=0;i<n;i++)
    {
        Visited[i]=0;
    }
    if(del>=0)//需要删除的顶点 
    {
        Visited[del]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(Visited[i]==0)
        {
            BFS(G,i);
        }
    }
    putchar('\n');
}