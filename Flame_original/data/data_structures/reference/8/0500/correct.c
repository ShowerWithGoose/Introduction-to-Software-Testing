#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 256
#define maxsize 1010
typedef struct edge{
	int adjvex;
	int weight;
	struct edge *next;
}elink; 
typedef struct ver{
	elink *link;
}vlink;
vlink G[max];
int V,E;
elink *insertedge(elink *head,int avex)
{
	elink *e,*p;
	elink *q=NULL;
	e=(elink *)malloc(sizeof(elink));
	e->adjvex=avex;
	e->weight=1;
	e->next=NULL;
	
	if(head==NULL)
	{
		return e;
	}
	for(p=head;p!=NULL&&p->adjvex<avex;q=p,p=p->next);
		if(p==head)
		{
			e->next=p;
			return e;
		}
	else
	{
		q->next=e;
		e->next=p;
		return head;
	}	
}
void create(vlink graph[])
{
	int i;
	for(i=0;i<E;i++)
	{
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		graph[v1].link=insertedge(graph[v1].link,v2);
		graph[v2].link=insertedge(graph[v2].link,v1);
	}
}
int visited[max]={0};
void dfs(vlink G[],int v)
{
	elink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
		if(!visited[p->adjvex])
			dfs(G,p->adjvex);
}
void traveld(vlink G[],int n,int delv)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	if(delv>=0)
		visited[delv]=1;
	for(i=0;i<n;i++)
		if(!visited[i])
		dfs(G,i);
	printf("\n");
}
//
int Q[maxsize];
int front,rear,cnt;
void init(void)
{
	front=0;
	rear=maxsize-1;
	cnt=0;
}
int empty(void)
{
	return cnt==0;
}
int full(void)
{
	return cnt==maxsize;
}
void in(int q[],int item)
{
	if(full())
		printf("full queue!");
	else{
		rear=(rear+1)%maxsize;
		q[rear]=item;
		cnt++;
	} 
}
int out(int q[])
{
	int a;
	if(empty())
		printf("empty queue!");
	else{
		a=q[front];
		cnt--;
		front=(front+1)%maxsize;
		return a;
	}
	return 0;
}
void bfs(vlink G[],int v)
{
	elink *p;
	init();
	visited[v]=1;
	in(Q,v);
	while(!empty())
	{
		v=out(Q);
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next)
			if(!visited[p->adjvex]){
				visited[p->adjvex]=1;
				in(Q,p->adjvex);
			}
	}	
}
void travelb(vlink G[],int n,int delv)
{
	int i;
	for(i=0;i<n;i++)
		visited[i]=0;
	if(delv>=0)
		visited[delv]=1;
	for(i=0;i<n;i++)
		if(!visited[i])
			bfs(G,i);
		printf("\n");
}
int main()
{
	scanf("%d %d",&V,&E);
		create(G);
	traveld(G,V,-1);
	travelb(G,V,-1);
		int j;
			scanf("%d",&j);
	traveld(G,V,j);
	travelb(G,V,j);
	
	return 0;
}








