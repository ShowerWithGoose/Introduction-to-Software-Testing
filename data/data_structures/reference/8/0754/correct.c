#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxV 300
int Q[MaxV];
int Front=0,Rear=MaxV-1,Count=0,num;
int empty(int Q[])
{
    return Count==0;
}
void enQueue(int item)
{
    Rear=(Rear+1)%MaxV; 
    Q[Rear]=item;
    Count++;
}
int deQueue()
{ 
	int e;
	e=Q[Front];
	Count--;
    Front=(Front+1)%MaxV;
    return e;
}
typedef struct edge{ 
       int adj;
       int wei;
       struct edge *next;
}Elink;
typedef struct ver{
       Elink *link;
}Vlink;
Vlink G[MaxV];
Elink *insertEdge(Elink *head,int avex)
{
    Elink *e,*p,*q;
    e=(Elink*)malloc(sizeof(Elink));
    e->adj=avex;e->wei=1;e->next=NULL;
    if(head==NULL){head=e;return head;}
    for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next);
	if(p==head){
    e->next=p;
	return e;}
	else{
    q->next = e;
    e->next = p;
	return head;}
}
void createGraph(){ 
  int i,m,v1,v2;
  scanf("%d%d",&num,&m);
  for(i=0;i<m;i++){
    scanf("%d%d",&v1,&v2);
    G[v1].link=insertEdge(G[v1].link,v2);
    G[v2].link=insertEdge(G[v2].link,v1);
  }
} 
int Visited[MaxV]={0};
void DFS(int v)
{
    Elink *p;
    Visited[v]=1;
    if(v>0)
    printf(" ");
    printf("%d",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    if(!Visited[p->adj])
    DFS(p->adj);
}
void travelDFS(int s)
{
    int i;
    for(i=0;i<num;i++)
	Visited[i]=0;
	if(s>0)
	Visited[s]=1;
    for(i=0;i<num;i++)
    if(!Visited[i])
	DFS(i);
}
void BFS(int v)
{
    Elink *p;
    Visited[v]=1;
    enQueue(v);
    while(!empty(Q)){
        v=deQueue();
        if(v>0)
    	printf(" ");
    	printf("%d",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adj]){
        Visited[p->adj]=1;
        enQueue(p->adj);
    	}
    }
}
void travelBFS(int s)
{
    int i;
    for(i=0;i<num;i++)
	Visited[i]=0;
	if(s>0)
	Visited[s]=1;
    for(i=0;i<num;i++)
    if(!Visited[i])
	BFS(i);
}
int main()
{
	int s;
	createGraph();
	scanf("%d",&s);
	travelDFS(0);
	printf("\n");
	travelBFS(0);
	printf("\n"); 
	travelDFS(s);
	printf("\n");
	travelBFS(s);
	return 0;
}

