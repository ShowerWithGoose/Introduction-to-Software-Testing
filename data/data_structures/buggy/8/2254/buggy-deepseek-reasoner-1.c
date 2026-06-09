#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MaxV 256
typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}Elink;
typedef struct ver{
    Elink *link;
}Vlink;
void createGraph(Vlink gragh[]);
void travelBFS(Vlink G[],int n,int x);
void travelDFS(Vlink G[],int n,int x);
Elink *insertEdge(Elink *head,int avex);
Vlink graph[MaxV]; // @@ The link fields of this global array are never initialized to NULL, causing undefined behavior when used in insertEdge.
int n,m; 
int main()
{
    scanf("%d%d",&n,&m);
    createGraph(graph);
    travelDFS(graph,n,-1);
    travelBFS(graph,n,-1);
    int x; // @@ Declaration after statements is not allowed in C89; may cause compilation error.
    scanf("%d",&x);
    travelDFS(graph,n,x);
    travelBFS(graph,n,x);
    return 0;
}
void createGraph(Vlink gragh[])
{
    for(int i=0;i<m;i++) // @@ C99 style loop variable declaration; may cause compilation error in older C standards.
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }
}
Elink *insertEdge(Elink *head,int avex)
{
    Elink *e,*p,*q=NULL;
    e=(Elink *)malloc(sizeof(Elink));
    e->adj=avex;e->wei=1;e->next=NULL;
    if(head==NULL) // @@ head may be garbage because graph[i].link is uninitialized; this condition may incorrectly fail.
    {
        head=e;
        return head;
    }
 for(p=head; p->next != NULL; p=p->next) // @@ Appending at end does not maintain ascending order of adjacency as required; should insert in sorted order.
        ;
    p->next = e;
    return head;

}
int Visited[MaxV]={0};
void DFS(Vlink G[],int v)
{
    Elink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    if(!Visited[p->adj])
    DFS(G,p->adj);
}
void travelDFS(Vlink G[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    Visited[i]=0;
        if(x>=0)
    Visited[x]=1;
    for(i=0;i<n;i++)
    if(!Visited[i])
    DFS(G,i);
    printf("\n");
}
#define MAXSIZE 1000
int Q[MAXSIZE]; 
int rear=MAXSIZE-1,front=0,count=0;
int emptyQ(void)
{
    if(count==0)
    return 1;
    else
    return 0;
}
void enQueue(int queue[],int item)
{
    rear=(rear+1)%MAXSIZE;
    queue[rear]=item;
    count++;
}
int deQueue(int queue[])
{
    int e;
    e=queue[front];
    count--;
    front=(front+1)%MAXSIZE;
    return e;
}
void BFS(Vlink G[],int v)
{
    Elink *p;
    Visited[v]=1;
    enQueue(Q,v);
    while(!emptyQ( ))
    {
        v=deQueue(Q);
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adj])
        {
            Visited[p->adj]=1;
            enQueue(Q,p->adj);
        }
    }
}
void travelBFS(Vlink G[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    Visited[i]=0;
    if(x>=0)
    Visited[x]=1;
    for(i=0;i<n;i++)
    {
        if(!Visited[i])
        BFS(G,i);
        printf("\n");
    }
}