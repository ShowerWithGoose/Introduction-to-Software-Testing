#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int nv,ne,key,nn[107]={0};
int que[1000];
int front,rear,n;


typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}Elink;

typedef struct ver{
    Elink *link;
}Vlink;
Vlink G[257];

Elink *insertEdge(Elink *head,int a)
{
    Elink *e,*p,*q=NULL;
    e=(Elink*)malloc(sizeof(Elink));
    e->adj=a;
    e->wei=1;
    e->next=NULL;
    if(head==NULL) return e;
    p=head;
    for(;p!=NULL && a>p->adj;q=p,p=p->next);
    if(p==head)
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

void Graph(Vlink graph[])
{
    int v1,v2;
    for(int i=0;i<ne;i++)
    {
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }
}

void DFS(Vlink G[],int v)
{
    Elink *p;
    if(v==0)printf("%d",v);
    else printf(" %d",v);
    nn[v]=1;
    for(p=G[v].link;p!=NULL;p=p->next)
        if(nn[p->adj]==0) DFS(G,p->adj);
}

void DFS1(Vlink G[])
{
    for(int i=0;i<nv;i++)
        nn[i]=0;
    for(int i=0;i<nv;i++)
        if(nn[i]==0) DFS(G,i);
    printf("\n");
}

void DFS2(Vlink G[])
{
    for(int i=0;i<nv;i++)
        nn[i]=0;
    nn[key]=1;
    for(int i=0;i<nv;i++)
        if(nn[i]==0) DFS(G,i);
    printf("\n");
}
void enqueue(int queue[],int v)
{
    if(n==1000) printf("error");
    else
    {
        rear=(rear+1)%1000;
        que[rear]=v;
        n++;
    }
}

int dequeue(int queue[])
{
    int e;
    if(n==0) printf("error");
    else
    {
        e=queue[front];
        n--;
        front=(front+1)%1000;
        return e;
    }
    return 0;
}

void BFS(Vlink G[],int v)
{
    Elink *p;
    front=0;
    rear=999;
    n=0;
    nn[v]=1;
    enqueue(que,v);
    while(n!=0)
    {
        v=dequeue(que);
        if(v==0) printf("%d",v);
        else printf(" %d",v);
        for(p=G[v].link;p!=NULL;p=p->next)
            if(nn[p->adj]==0)
            {
                nn[p->adj]=1;
                enqueue(que,p->adj);
            }
    }
}

void BFS1(Vlink G[])
{
    for(int i=0;i<nv;i++)
        nn[i]=0;
    for(int i=0;i<nv;i++)
        if(!nn[i]) BFS(G,i);
    printf("\n");
}

void BFS2(Vlink G[])
{
    for(int i=0;i<nv;i++)
        nn[i]=0;
    nn[key]=1;
    for(int i=0;i<nv;i++)
        if(!nn[i]) BFS(G,i);
    printf("\n");
}

int main()
{
    scanf("%d %d",&nv,&ne);
    Graph(G);
    scanf("%d",&key);
    DFS1(G);
    BFS1(G);
    DFS2(G);
    BFS2(G);
    return 0;
}

