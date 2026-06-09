#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 105
int Visited[maxsize];
int front,rear,count;
int Q[maxsize];
void initQueue()
{
    front=0;
    rear=maxsize-1;
    count=0;
}
typedef struct edge{
    int adj;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink graph[maxsize];
ELink *insertEdge(ELink *head,int avex);
void travelDFS(VLink G[],int n,int dv)
{
    int i;
    for(i=0;i<n;i++) Visited[i]=0;
    if(dv<n) Visited[dv]=1;
    for(i=0;i<n;i++)
        if(Visited[i]==0) DFS(G,i);
    printf("\n");
}
void DFS(VLink G[],int cancel)
{
    ELink *p;
    Visited[cancel]=1;
    printf("%d ",cancel);
    for(p=G[cancel].link;p!=NULL;p=p->next)
        if(Visited[p->adj]==0)
            DFS(G,p->adj);
}
int isFull()
{
    return count==maxsize;
}
int isEmpty()
{
    return count==0;
}
void enQueue(int item)
{
    if(!isFull()){
        rear=(rear+1)%maxsize;
        Q[rear]=item;
        count++;
    }
}
int deQueue()
{
    int e;
    if(!isEmpty())
    {
        e=Q[front];
        count--;
        front=(front+1)%maxsize;
        return e;
    }
}
void travelBFS(VLink G[],int n,int dv)
{
    initQueue();
    int i;
    for(i=0;i<n;i++) Visited[i]=0;
    if(dv<n) Visited[dv]=1;
    for(i=0;i<n;i++)
        if(Visited[i]==0) BFS(G,i);
    printf("\n");
}
void BFS(VLink G[],int cancel)
{
    ELink *p;
    Visited[cancel]=1;
    enQueue(cancel);
    while(!isEmpty()){
        cancel=deQueue();
        printf("%d ",cancel);
        for(p=G[cancel].link;p!=NULL;p=p->next)
        if(Visited[p->adj]==0){
            Visited[p->adj]=1;
            enQueue(p->adj);
        }
    }
}
void createGraph(int v1,int v2,VLink graph[])
{
    graph[v1].link=insertEdge(graph[v1].link,v2);
    graph[v2].link=insertEdge(graph[v2].link,v1);
}
ELink *insertEdge(ELink *head,int avex)
{
    ELink *e,*p;
    e=(ELink *)malloc(sizeof(ELink));
    e->adj=avex;e->next=NULL;
    if(head==NULL){head=e;return head;}
    for(p=head;p->next!=NULL && p->next->adj<avex;p=p->next);
    if(p==head && p->adj>avex)
    {
        e->next=p;
        return e;
    }
    else if(p->next==NULL) p->next=e;
    else{
        e->next=p->next;
        p->next=e;
    }
    return head;
}
int main()
{
    ELink *p;
    int i,v1,v2,m,n,cancel;
    scanf("%d%d",&m,&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&v1,&v2);
        createGraph(v1,v2,graph);
    }
    travelDFS(graph,m,m);
    travelBFS(graph,m,m);
    scanf("%d",&cancel);
    travelDFS(graph,m,cancel);
    travelBFS(graph,m,cancel);
    return 0;
}

