#include <stdio.h>
#include <stdlib.h>
#define MaxV 256
#define MAXSIZE 1000
typedef struct edge{
    int  adj;
    int  wei;
    struct edge *next;
} ELink;
typedef struct ver{
    ELink *link;
} VLink;
VLink G[1000];
ELink *insertEdge(ELink *head,int avex)
{
    ELink *e,*p,*q = NULL;
    e=(ELink*)malloc(sizeof(ELink));
    e->adj=avex;e->wei=1;e->next=NULL;
    if(head==NULL)
        return e;
    for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next);
    if(p==head){
        e->next=p;
        return e;
    }
    else {
        q->next=e;
        e->next=p;
        return head;
    }
}
int Visited[MaxV]={0};
void DFS(VLink G[ ],int v)
{
    ELink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adj])
            DFS(G,p->adj);
}
void createGraph(VLink graph[],int E)
{
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}
void  travelDFS(VLink  G[ ],int n,int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i]=0;
    if(delV >= 0)
        Visited[delV]=1;
    for(i=0;i<n;i++)
        if(!Visited[i])
		DFS(G,i);
    printf("\n");
}
int Q[MAXSIZE];
int Front,Rear,Count;
void  initQueue(void)
{
    Front=0;
    Rear=MAXSIZE-1;
    Count=0;
}
int isFull()
{
    return Count == MAXSIZE;
}
int isEmpty()
{
    return Count == 0;
}

void enQueue(int queue[ ], int item)
{
    if(!isFull()){
		Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;		
	}
        
}
int deQueue(int queue[ ])
{
    int e;
    
        e=queue[Front];
        Count--;
        Front=(Front+1)%MAXSIZE;
        return e;
}
void BFS(VLink G[ ], int v)
{
    ELink *p;
    initQueue();
    Visited[v]=1;
    enQueue(Q,v);
    while(!isEmpty()){
        v=deQueue(Q);
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next )
            if(!Visited[p->adj]) {
                Visited[p->adj] = 1;
                enQueue(Q, p->adj);
            }
    }
}
void travelBFS(VLink  G[ ],int n,int delV)
{
    int i;
    for(i=0;i<n;i++)
        Visited[i] = 0 ;
    if(delV>=0)
        Visited[delV]=1;
    for(i=0;i<n;i++)
        if(!Visited[i])
            BFS(G,i);
    printf("\n");
}
int main() {
    int n,V,E;
    scanf("%d%d",&V,&E);
    createGraph(G,E);
    travelDFS(G,V,-1);
    travelBFS(G,V,-1);
    scanf("%d",&n);
    travelDFS(G,V,n);
    travelBFS(G,V,n);
    return 0;
}

