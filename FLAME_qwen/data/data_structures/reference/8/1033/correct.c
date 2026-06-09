#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct edge
{
    int id;
    struct edge *next;
}Elink;

typedef struct ver
{
    Elink *edge;
}Vlink;

typedef struct queue
{
    int *data;
    int head,tail;
    int cnt;
    int size;
}Queue;

Vlink *ver[MAX];
int visit[MAX];
Queue *q;

Queue *init(int n)
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->data=(int*)malloc(sizeof(int)*n);
    q->head=q->tail=0;
    q->size=n;
    q->cnt=0;
    return q;
}

Vlink *getV()
{
    Vlink *v=(Vlink*)malloc(sizeof(Vlink));
    v->edge=NULL;
    return v;
}

void enQueue(int id)
{
    if(q->size==q->cnt)
    {
        printf("Full\n");
        return ;
    }
    q->data[q->tail]=id;
    q->tail++;
    if(q->tail==q->size) q->tail=0;
    q->cnt++;
    return ;
}

void outQueue()
{
    if(q->cnt==0)
    {
        printf("Empty\n");
        return ;
    }
    q->head++;
    if(q->head==q->size) q->head=0;
    q->cnt--;
    return ;
}

void clearQ(Queue *q)
{
    free(q->data);
    free(q);
    return ;
}

void insertEdge(Vlink *ver,int id)
{
    Elink *p=ver->edge;
    Elink *e=(Elink*)malloc(sizeof(Elink));
    e->id=id;e->next=NULL;
    if(p==NULL) ver->edge=e;
    else{
        if(id<p->id)
        {
            e->next=p;
            ver->edge=e;
        }
        else
        {
            while(p->next&&id>p->next->id) p=p->next;
            e->next=p->next;
            p->next=e;
        }
    }
    return ;
}

void createGraph(int n)
{
    int i;
    int a,b;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        insertEdge(ver[a],b);
        insertEdge(ver[b],a);
    }
    return ;
}

void DFS(int id)
{
    if(visit[id]) return ;
    visit[id]=1;
    Elink *p=ver[id]->edge;
    printf("%d ",id);
    while(p)
    {
        DFS(p->id);
        p=p->next;
    }
    return ;
}

void BFS(int id)
{
    if(q->cnt==0) return ;
    if(!visit[id]){
        visit[id]=1;
        Elink *e=ver[id]->edge;
        printf("%d ",id);
        while(e)
        {
            enQueue(e->id);
            e=e->next;
        }
    }
    outQueue();
    BFS(q->data[q->head]);
    return ;
}

void clearE(Elink *e)
{
    Elink *p;
    while(e)
    {
        p=e->next;
        free(e);
        e=p;
    }
    return ;
}

void clearV(Vlink* v)
{
    clearE(v->edge);
    free(v);
    return ;
}

int main()
{
    int n,m,p;
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) ver[i]=getV();
    createGraph(m);
    scanf("%d",&p);
    q=init(MAX);
    for(i=0;i<n;i++)
    {
        if(visit[i]) continue;
        DFS(i);
    }
    printf("\n");
    for(i=0;i<n;i++) visit[i]=0;
    enQueue(0);
    for(i=0;i<n;i++)
    {
        if(visit[i]) continue;
        BFS(i);
    }
    printf("\n");
    for(i=0;i<n;i++) visit[i]=0;
    visit[p]=1;
    for(i=0;i<n;i++)
    {
        if(visit[i]) continue;
        DFS(i);
    }
    printf("\n");
    for(i=0;i<n;i++) visit[i]=0;
    visit[p]=1;
    clearQ(q);
    q=init(MAX);
    enQueue(0);
    for(i=0;i<n;i++)
    {
        if(visit[i]) continue;
        BFS(i);
    }
    printf("\n");
    clearQ(q);
    for(i=0;i<n;i++)
    {
        clearV(ver[i]);
    }
    return 0;
}

