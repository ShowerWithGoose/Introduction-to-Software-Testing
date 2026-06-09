#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define maxV 100

typedef struct edge{
	int adjvex;
	struct edge *next;
}Elink;
typedef struct ver{
	int vertex;
	Elink *link;
}Vlink;
Vlink G[maxV];
int n,ver;
int Visited[maxV]={0};
int front=0,count=0,rear=-1;
int queue[maxV]={};

void createGraph();
Elink *insertEdge();
void deleteEdge();
void travelDFS();
void travelBFS();

int main()
{
	scanf("%d %d",&n,&ver);
	createGraph();
	int dver,i;
	scanf("%d",&dver);
	
	travelDFS();
	printf("\n");
	travelBFS();
	printf("\n");
	
	deleteEdge(dver);
	
	travelDFS();
	printf("\n");
	travelBFS();
    return 0;
}

void createGraph()
{
	int i,v1,v2;
	for(i=0;i<ver;i++){
		scanf("%d %d",&v1,&v2);
		G[v1].link=insertEdge(G[v1].link,v2,v1);
		G[v2].link=insertEdge(G[v2].link,v1,v2);
	}
}

Elink *insertEdge(Elink *head,int avex,int v1)
{
	Elink *e,*p,*j;
	e=(Elink*)malloc(sizeof(Elink));
	e->adjvex=avex;
	e->next=NULL;
	if(head==NULL){
		head=e;
		return head;
	}
	if(e->adjvex<head->adjvex){
		G[v1].link=e;
		e->next=head;
		head=G[v1].link;
		return head;
	}
	for(p=head;p->next!=NULL&&p->next->adjvex<e->adjvex;p=p->next) ;
		e->next=p->next;
		p->next=e;
		return head;
}

void DFS(int v)
{
	Elink *p;
	Visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	    if(!Visited[p->adjvex])
	        DFS(p->adjvex);
}

void travelDFS()
{
	int i;
	for(i=0;i<n;i++)Visited[i]=0;
	for(i=0;i<n;i++){
		if(G[i].link==NULL)
		    continue;
	    if(!Visited[i])DFS(i);
	}
}

void enQueue(int item)
{
	rear++;
	queue[rear]=item;
	count++;
}

int deQueue()
{
	int e;
	e=queue[front++];
	count--;
	return e;
}

void BFS(int v)
{
	Elink *p;
	printf("%d ",v);
	Visited[v]=1;
	enQueue(v);
	while(count!=0){
		v=deQueue();
		p=G[v].link;
		for(;p!=NULL;p=p->next)
		    if(!Visited[p->adjvex]){
		    	printf("%d ",p->adjvex);
		    	Visited[p->adjvex]=1;
		    	enQueue(p->adjvex);
			} 
	}
}

void travelBFS()
{
	int i;
	for(i=0;i<n;i++)Visited[i]=0;
	for(i=0;i<n;i++){
		if(G[i].link==NULL)
		    continue;
	    if(!Visited[i])BFS(i);
	}
}

void deleteEdge(int v)
{
	int i;
	Elink *p,*q;
	G[v].link=NULL;
	for(i=0;i<n;i++){
		if(G[i].link==NULL)
		    continue;
		if(G[i].link->adjvex==v){
			q=G[i].link->next;
			G[i].link=q;
		}
		else{
		for(p=G[i].link;p->next!=NULL;p=p->next){
			if(p->next->adjvex==v){
				q=p->next->next;
				p->next=q;
				break;
			}
		}
	}
}
}

