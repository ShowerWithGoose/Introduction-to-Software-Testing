#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxV 150

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
struct vertex a[MaxV];
//函数声明 
void creatGraph(Vlink graph[],int n,struct vertex b[]);
Elink *insertEdge(Elink *head,int avex);
void travelDFS(Vlink G[],int n);
void travelDFS_(Vlink G[],int n,int m);
void DFS(Vlink G[],int v);
void bubblesort(struct vertex a[],int n);
void travelBFS(Vlink G[],int n);
void travelBFS_(Vlink G[],int n,int m);
void BFS(Vlink G[],int v);



//全局变量
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
	scanf("%d%d",&a[i].v1,&a[i].v2);
	for(i=0;i<n_e;i++)
	{
		if(a[i].v1>a[i].v2)
		{
			temp=a[i].v1;
			a[i].v1=a[i].v2;
			a[i].v2=temp;
		}
	}
	bubblesort(a,i);
	creatGraph(G,n_e,a);
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


//冒泡排序 
void bubblesort(struct vertex a[],int n)
{
	int i,j,flag;
	struct vertex hold;
	for(i=0;i<n-1;i++)
	{
		flag = 0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j].v1>a[j+1].v1)
			{
				hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
				flag = 1;
			}
			else if(a[j].v1==a[j+1].v1)
			{
				if(a[j].v2>a[j+1].v2)
				{
					hold = a[j];
					a[j] = a[j+1];
					a[j+1] = hold;
					flag = 1;
				}
			}
		}
		if(flag==0)
		{
			break;
		}
	}
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


