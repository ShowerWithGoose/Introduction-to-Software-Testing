#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct edge
{
    int adjvex;
    struct edge *next;
}Elink;
typedef struct ver
{
    Elink *link;
}Vlink;

void creatgraph(Vlink G[],int m,int n)
{
    Elink *p,*q;
    p=(Elink *)malloc(sizeof(Elink));
    p->adjvex=n;
    if(G[m].link==NULL||n<G[m].link->adjvex)
    {
        p->next=G[m].link;
        G[m].link=p;
    }
    else
    {
        for(q=G[m].link;q->next!=NULL&&q->next->adjvex<n;q=q->next);
        p->next=q->next;
        q->next=p;
    }
    
}

void DFS(Vlink G[],int visit[],int v)
{
    Elink *p;
    visit[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(visit[p->adjvex]==0)
            DFS(G,visit,p->adjvex);
}

int Q[100];
int front=0,rear=-1;

void enqueue(int p)
{
    if(rear!=99)
        Q[++rear]=p;
}

int dequeue()
{
    if(front<=rear)
        return Q[front++];
    return 0;
}

void BFS(Vlink G[],int visit[],int v)
{
    Elink *p;
    visit[v]=1;
    printf("%d ",v);
    enqueue(v);
    while(front<=rear)
    {
        v=dequeue();
        p=G[v].link;
        for(;p!=NULL;p=p->next)
            if(visit[p->adjvex]==0)
            {
                visit[p->adjvex]=1;
                printf("%d ",p->adjvex);
                enqueue(p->adjvex);
            }
    }
}

signed main()
{
    int v,l;
    scanf("%d%d",&v,&l);
    Vlink G[v];
    int visit[v];
    for(int i=0;i<v;i++)
        G[i].link=NULL;
    while(l--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        creatgraph(G,m,n);
        creatgraph(G,n,m);
    }
    int delete;
    scanf("%d",&delete);  
    memset(visit,0,sizeof(visit));
    DFS(G,visit,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    BFS(G,visit,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[delete]=1;
    DFS(G,visit,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[delete]=1;
    BFS(G,visit,0);
    return 0;
}


