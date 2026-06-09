#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MaxV 256
#define MAX 1000
typedef struct edge{
    int adjvex;
    int wei;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink G[MaxV];
int V,E;
void createGraph(VLink graph[]);
void travelDFS(VLink G[ ],int n,int delV);
void travelBFS(VLink G[ ],int n,int delV);
int main(int argc,const char * argv[]) {
    scanf("%d %d",&V,&E);
    createGraph(G);
    travelDFS(G,V,-1);
    travelBFS(G,V,-1);
    int s;
    scanf("%d",&s);
    travelDFS(G,V,s);
    travelBFS(G,V,s);
    return 0;
}
ELink *insertEdge(ELink *head,int avex)
{
    ELink *e,*p,*q=NULL;
    e =(ELink *)malloc(sizeof(ELink)); 
    e->adjvex=avex;
	e->wei=1; 
	e->next =NULL;
    if(head==NULL)
        return e;
    for(p=head;p!=NULL&&avex>p->adjvex;q=p,p=p->next);
    if(p==head){
        e->next =p;
        return e;
    }
    else{          
        q->next =e;
        e->next =p;
        return head;
    }
}
void createGraph(VLink graph[])
{
	int i;
    for(i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }
}
int Visited[MaxV]={0}; 
void DFS(VLink G[ ],int v)
{
    ELink *p;
    Visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adjvex])
            DFS(G,p->adjvex);
}
void travelDFS(VLink G[ ],int n,int delV)
{
    int i;
    for(i=0;i<n;i++)
        Visited[i]=0;
    if(delV>=0)
        Visited[delV]=1;
    for(i=0;i<n;i++){
        if(!Visited[i]){
		DFS(G,i);
	}
}
    printf("\n");
}
int Q[MAX];
int f,r,c;
void initQueue(void)
{
    f=0;
    r=MAX-1;
    c=0;
}
int isEmpty(void)
{
    return c==0;
}
int isFull(void)
{
    return c==MAX;
}
void enQueue(int queue[ ],int item)
{
    if(!isFull()){                      
        r=(r+1)%MAX;
        queue[r]=item;
        c++;
    }
}
int deQueue(int queue[ ])
{
    int e;
    if(!isEmpty()){                       
        e=queue[f];
        c--;
        f=(f+1)%MAX;
        return e;
    }
    return 0;
}
void BFS(VLink G[ ],int v)
{
    ELink *p;
    initQueue();
    Visited[v]=1;
    enQueue(Q,v);
    while(!isEmpty()){
        v=deQueue(Q);
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next ) 
        if(!Visited[p->adjvex ]){
                Visited[p->adjvex]=1; 
                enQueue(Q,p->adjvex);
            }
}
}
void travelBFS(VLink G[ ],int n,int delV)
{
    int i;
    for(i=0;i<n;i++)
        Visited[i]=0 ;
    if(delV>=0)
        Visited[delV]=1;
    for(i=0;i<n;i++)
        if(!Visited[i])
            BFS(G,i);
    printf("\n");
}

