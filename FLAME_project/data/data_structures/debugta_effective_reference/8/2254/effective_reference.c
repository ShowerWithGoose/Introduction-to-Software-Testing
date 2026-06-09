#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MaxV 256
typedef struct edge{
	int adj;
	int wei;
	struct edge * next;
}Elink;

typedef struct ver{
	Elink *link;
}Vlink;
Vlink graph[MaxV];
int n,m;
void createGraph(Vlink graph[]);
Elink *insertEdge(Elink *head,int avex);

int Visited[MaxV]={0};
void travelDFS(Vlink graph[],int n);
void travelDFS2(Vlink graph[],int n,int dev);
void DFS(Vlink graph[],int v);

void travelBFS(Vlink graph[],int n);
void travelBFS2(Vlink graph[],int n,int dev);
void BFS(Vlink graph[],int v);
#define MAXSIZE 1000
int Q[MAXSIZE];
int front,rear,count;
int isEmpty(void);
void enQueue(int queue[],int item);
int deQueue(int queue[]);
int main(){
	int x;
	scanf("%d %d",&n,&m);
	 createGraph(graph);
	scanf("%d",&x);
	
	travelDFS(graph,n);
	travelBFS(graph,n);
	travelDFS2(graph,n,x);
	travelBFS2(graph,n,x);
	return 0;
}

void createGraph(Vlink graph[]){
	int i,n,v1,v2;
	n=m;
	for(i=0;i<n;i++){
		scanf("%d %d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
	}
}

Elink *insertEdge(Elink *head,int avex){
	Elink *e,*p,*q=NULL;
	e=(Elink *)malloc(sizeof(Elink));
	e->adj=avex;
	e->wei=1;
	e->next=NULL;
	if(head==NULL){
		return e;
	}
	for(p=head;p!=NULL&&p->adj<avex;q=p,p=p->next);
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

void travelDFS(Vlink graph[],int n){
	int i;
	for(i=0;i<n;i++){
		Visited[i]=0;
	}
	for(i=0;i<n;i++){
		if(!Visited[i]){
			DFS(graph,i);
		}
	}
	printf("\n");
}

void DFS(Vlink graph[],int v){
	Elink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=graph[v].link;p!=NULL;p=p->next){
		if(!Visited[p->adj]){
			DFS(graph,p->adj);
		}
	}
}

void travelBFS(Vlink graph[],int n){
	int i;
	for(i=0;i<n;i++){
		Visited[i]=0;
	}
	for(i=0;i<n;i++){
		if(!Visited[i]){
			BFS(graph,i);
		}
	}
	printf("\n");
}

void BFS(Vlink graph[],int v){
	Elink *p;
	front=0;
	rear=MAXSIZE-1;
	count=0;
	Visited[v]=1;
	enQueue(Q,v);
	while(!isEmpty()){
		v=deQueue(Q);
		printf("%d ",v);
		for(p=graph[v].link;p!=NULL;p=p->next){
			if(!Visited[p->adj]){
				Visited[p->adj]=1;
				enQueue(Q,p->adj);
			}
		}
	}
	
}

int isEmpty(void){
	return count==0;
}

void enQueue(int queue[],int item){
	if(count==MAXSIZE){
		printf("Full queue!");
	}
	else{
		rear=(rear+1)%MAXSIZE;
		queue[rear]=item;
		count++;
	}
}

int deQueue(int queue[]){
	int e;
	if(isEmpty()){
		printf("Empty queue!");
	}
	else{
		e=queue[front];
		count--;
		front=(front+1)%MAXSIZE;
		return e;
	}
	return 0;
}

void travelDFS2(Vlink graph[],int n,int dev){
	int i;
	for(i=0;i<n;i++){
		Visited[i]=0;
	}
	
	Visited[dev]=1;
	
	for(i=0;i<n;i++){
		if(!Visited[i]){
			DFS(graph,i);
		}
	}
	printf("\n");
}

void travelBFS2(Vlink graph[],int n,int dev){
	int i;
	for(i=0;i<n;i++){
		Visited[i]=0;
	}
	Visited[dev]=1;
	for(i=0;i<n;i++){
		if(!Visited[i]){
			BFS(graph,i);
		}
	}
	printf("\n");
}

