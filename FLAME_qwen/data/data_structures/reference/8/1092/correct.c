#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105
typedef struct edge{
    int adj;
    struct edge *next;
}Elink;
typedef struct ver{
    Elink *link;
}Vlink;
Vlink G[N];
int Q[N];
int front=0,rear=N-1,len=0;
int Visited[N]={0};
void enQueue(int v);
int deQueue(int Q[]);
int isempty();
void travelDFS(int v);
void travelBFS(int v);
Elink *insertEdge(Elink* head,int avex);
void deleteVex(int v);
int main()
{
    int vnum,snum;
    int i,v1,v2,dv;
    scanf("%d%d",&vnum,&snum);
    for(i=0;i<snum;i++)
    {
        scanf("%d%d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link,v2);
        G[v2].link=insertEdge(G[v2].link,v1);
    }
    scanf("%d",&dv);
    travelDFS(0);
    printf("\n");
    
    memset(Visited,0,sizeof(Visited));
    travelBFS(0);
    printf("\n");

    memset(Visited,0,sizeof(Visited));
    Visited[dv]=1;
    travelDFS(0);
    printf("\n");

    memset(Visited,0,sizeof(Visited));
    Visited[dv]=1;
    travelBFS(0);
    printf("\n");
    return 0;
}

void travelDFS(int v)
{
    Elink* p;
    printf("%d ",v);
    Visited[v]=1;
    for(p=G[v].link;p!=NULL;p=p->next)
      if(!Visited[p->adj])
        travelDFS(p->adj);
}

void travelBFS(int v)
{
    Elink* p;
    enQueue(v);
    while(!isempty()){
        v=deQueue(Q);
        printf("%d ",v);
        Visited[v]=1;
        for(p=G[v].link;p!=NULL;p=p->next)
          if(!Visited[p->adj]){
              Visited[p->adj]=1;
              enQueue(p->adj);
          }
    }
}

Elink *insertEdge(Elink* head,int avex)
{
    Elink *e,*p;
    e=(Elink*)malloc(sizeof(Elink));
    e->adj=avex;
    e->next=NULL;
    if(head==NULL) 
    {
        head=e;
        return head;
    }
    if(avex<head->adj)
    {
        e->next=head;
        head=e;
    }
    else
    {
       for(p=head;p->next!=NULL&&(p->next->adj<avex);p=p->next);
       e->next=p->next;
       p->next=e;
    }
    return head;
}

int isempty()
{
    return len==0;
}

void enQueue(int v)
{
    rear=(rear+1)%N;
    Q[rear]=v;
    len++;
}

int deQueue(int Q[])
{
    int v;
    v=Q[front];
    len--;
    front=(front+1)%N;
    return v;
}
