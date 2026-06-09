#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
#define MaxV 256
#define max 1000
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}ELink;
typedef struct ver{
	ELink *link;
}VLink;
VLink G[MaxV];

int V,E;

ELink *insertedge(ELink *head,int avex){
	ELink *e,*p,*q=NULL;
	e=(ELink *)malloc(sizeof(ELink));
	e->adj=avex;e->wei=1;e->next=NULL;
	if(head==NULL){
		return e;
	}
	for(p=head;p!=NULL&&avex>p->adj;q=p,p=p->next);
	if(p==head){
		e->next=p;
		return e;
	}
	else{
		q->next=e;
		e->next=p;
		return head;
	}
}
void creategraph(VLink graph[]){
	int i,v1,v2;
	for(i=0;i<E;i++){
		scanf("%d %d",&v1,&v2);
		graph[v1].link=insertedge(graph[v1].link,v2);
		graph[v2].link=insertedge(graph[v2].link,v1);
	}
}

int Visited[MaxV]={};
void DFS(VLink G[],int v){
	ELink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	if(!Visited[p->adj])
	DFS(G,p->adj);
}
void travelDFS(VLink G[],int n,int op){
	int i;
	for(i=0;i<n;i++)
	Visited[i]=0;
	if(op>=0)
	Visited[op]=1;
	for(i=0;i<n;i++)
	if(!Visited[i])
	DFS(G,i);
	printf("\n");
}

int front=0,rear=max-1,count=0;
int Q[max]; 
void enqueue(int queue[],int item){
	rear=(rear+1)%max;
	queue[rear]=item;
	count++;
}
int dequeue(int queue[]){
	int e;
	e=queue[front];
	count--;
	front=(front+1)%max;
	return e;
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enqueue(Q, v);
    while(count!=0){
         v = dequeue(Q);  //取出队头元素
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enqueue(Q, p->adj);
           }
     }
}
void  travelBFS(VLink  G[ ], int n,int op)
{
    int i;
    for(i=0; i<n; i++) 
	Visited[i] = 0 ;
	if(op>=0)
	Visited[op]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
	    BFS(G, i);
	printf("\n");
}

int main(){
	scanf("%d%d",&V,&E);
	creategraph(G);
	travelDFS(G,V,-1);
	travelBFS(G,V,-1);
	
	int todelete;
	scanf("%d",&todelete);
	
	travelDFS(G,V,todelete);
	travelBFS(G,V,todelete);
}


