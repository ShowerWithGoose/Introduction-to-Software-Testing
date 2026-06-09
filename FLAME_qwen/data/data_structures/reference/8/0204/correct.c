#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxV 200

//结构体 
typedef struct edge{
	int adj;//边结点(用另一个顶点表示)
	int wei;
	struct edge *next; 
}Elink;

typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[MaxV]; 

struct vertex{
	int v1;
	int v2;
};
struct vertex ab[MaxV];
//函数声明 
void creatGraph(Vlink graph[],int n,struct vertex b[]);
Elink *insertEdge(Elink *head,int avex);
void travelDFS(Vlink G[],int n);
void travelDFS_(Vlink G[],int n,int m);
void DFS(Vlink G[],int v);
void travelBFS(Vlink G[],int n);
void travelBFS_(Vlink G[],int n,int m);
void BFS(Vlink G[],int v);
int cmp(const void*_a,const void*_b);


int Visit[MaxV]; 
int top=0,end=0;
int Q[MaxV];

int main()
{
	int n_v,n_e,i,temp;
	int de_v;
	int v1[MaxV],v2[MaxV];
	scanf("%d%d",&n_v,&n_e);
	for(i=0;i<n_e;i++)
	scanf("%d%d",&ab[i].v1,&ab[i].v2);
	for(i=0;i<n_e;i++)
	{
		if(ab[i].v1>ab[i].v2)
		{
			temp=ab[i].v1;
			ab[i].v1=ab[i].v2;
			ab[i].v2=temp;
		}
	}
	qsort(ab,n_e,sizeof(ab[0]),cmp);
	creatGraph(G,n_e,ab);
	scanf("%d",&de_v);
	travelDFS(G,n_v);
	printf("\n");
	travelBFS(G,n_v);
	printf("\n");
	travelDFS_(G,n_v,de_v);
	printf("\n");
	travelBFS_(G,n_v,de_v);
	return 0; 
} 

void creatGraph(Vlink graph[],int n,struct vertex b[])
{
	int i;
	for(i=0;i<n;i++)
	{
		graph[b[i].v1].link=insertEdge(graph[b[i].v1].link,b[i].v2);
		graph[b[i].v2].link=insertEdge(graph[b[i].v2].link,b[i].v1);
	}
}

Elink *insertEdge(Elink *head,int avex)
{
	Elink *e,*p;
	e = (Elink *)malloc(sizeof(Elink));
	e->adj=avex;
	e->wei=1;
	e->next=NULL;
	if(head==NULL)
	{
		head = e;
		return head;
	}
	for(p=head;p->next!=NULL;p=p->next);
	p->next=e;
	return head;
	
}


//深度优先遍历 
void travelDFS(Vlink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Visit[i]=0;
	}
	for(i=0;i<n;i++)
		if(!Visit[i])
			DFS(G,i);
	 
}
 
void travelDFS_(Vlink G[],int n,int m)
{
	int i;
	for(i=0;i<n;i++)
	{
		Visit[i]=0;
	}
	Visit[m]=1;
	for(i=0;i<n;i++)
		if(!Visit[i])
			DFS(G,i);
	 
}

void DFS(Vlink G[],int v)
{
	Elink *p;
	Visit[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(!Visit[p->adj])
			DFS(G,p->adj);
	}
	
}



//qsort
int cmp(const void*_a,const void*_b)
{
	struct vertex *a =(struct vertex *)_a;
	struct vertex *b =(struct vertex *)_b;
	if(a->v1 > b->v1) return 1;
	else if(a->v1==b->v1)
	{
		if(a->v2 > b->v2)
			return 1;
		else return -1;
	}
	else return -1;
	
}



//广度优先遍历 
void travelBFS(Vlink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Visit[i]=0;
	}
	for(i=0;i<n;i++)
		if(!Visit[i])
			BFS(G,i);
	 
}
void travelBFS_(Vlink G[],int n,int m)
{
	int i;
	for(i=0;i<n;i++)
	{
		Visit[i]=0;
	}
	Visit[m]=1;
	for(i=0;i<n;i++)
		if(!Visit[i])
			BFS(G,i);
	 
}
void BFS(Vlink G[],int v)
{
	Elink *p;
	printf("%d ",v);
	Visit[v]=1;
	Q[end++]=v;
	while(end>top)
	{
		v = Q[top];
		top++;
		p = G[v].link;
		for(;p!=NULL;p=p->next)
			if(!Visit[p->adj])
			{
				printf("%d ",p->adj);
				Visit[p->adj]=1;
				Q[end++]=p->adj;
			}
	}
}


