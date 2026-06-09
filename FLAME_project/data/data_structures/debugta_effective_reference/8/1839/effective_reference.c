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
vlink V[max];
int n,e;
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
	for(i=0;i<e;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].link=insertedge(graph[a].link,b);
		graph[b].link=insertedge(graph[b].link,a);
	}
}
int isus[max]={0};
void dfs(vlink V[],int v)
{
	elink *p;
	isus[v]=1;
	printf("%d ",v);
	for(p=V[v].link;p!=NULL;p=p->next)
		if(!isus[p->adjvex])
			dfs(V,p->adjvex);
}
void traveld(vlink V[],int n,int delv)
{
	int i;
	for(i=0;i<n;i++)
	isus[i]=0;
	if(delv>=0)
		isus[delv]=1;
	for(i=0;i<n;i++)
		if(!isus[i])
		dfs(V,i);
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
void bfs(vlink V[],int v)
{
	elink *p;
	init();
	isus[v]=1;
	in(Q,v);
	while(!empty())
	{
		v=out(Q);
		printf("%d ",v);
		for(p=V[v].link;p!=NULL;p=p->next)
			if(!isus[p->adjvex]){
				isus[p->adjvex]=1;
				in(Q,p->adjvex);
			}
	}	
}
void travelb(vlink V[],int n,int delv)
{
	int i;
	for(i=0;i<n;i++)
		isus[i]=0;
	if(delv>=0)
		isus[delv]=1;
	for(i=0;i<n;i++)
		if(!isus[i])
			bfs(V,i);
		printf("\n");
}
int main()
{
	scanf("%d %d",&n,&e);
		create(V);
	traveld(V,n,-1);
	travelb(V,n,-1);
		int q;
			scanf("%d",&q);
	traveld(V,n,q);
	travelb(V,n,q);
	
	return 0;
}








