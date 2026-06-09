#include<stdio.h>
#include<stdlib.h>
typedef struct edge
{
	int adj;//表示顶点 
	int weight;
	struct edge *next;
 }elink;
 typedef struct ver
 {
 	int vertex;
 	int flag;
 	elink *link;
 }vlink;
vlink g[110];
int visited[100];
int que[100];//代表队列
elink *insertedge(elink *head,int avex);
void creatgraph(vlink graph[],int v1,int v2);
void DFS(vlink g[],int v);
void BFS(vlink g[],int v);
void start(int dot);
int main()
{
	int i=0,j=0,k=0;
	int dot,ed,del;
	int a=0,b=0;
	scanf("%d %d",&dot,&ed);
	for(i=0;i<ed;i++)
	{
		scanf("%d %d",&a,&b);
		creatgraph(g,a,b);
	}
	for(i=0;i<dot;i++)
	g[i].flag=1;
	scanf("%d",&del);
	elink *p;
	/*for(i=0;i<dot;i++)
	{
		printf("%d ",i);
		p=g[i].link;
		for(;p!=NULL;p=p->next)
		printf("%d ",p->adj);
		printf("\n");
	}*/
	DFS(g,0);
	printf("\n");
	start(dot);
	BFS(g,0);
	printf("\n");
	start(dot);
	g[del].flag=0;
	DFS(g,0);
	printf("\n");
	start(dot);
	BFS(g,0);
	printf("\n");
	start(dot);
	return 0;
}
void creatgraph(vlink graph[],int v1,int v2)
 {
 	graph[v1].link=insertedge(graph[v1].link,v2);
	graph[v2].link=insertedge(graph[v2].link,v1);
}
elink *insertedge(elink *head,int avex)//avex戴表我要插入的顶点 
{
	elink *e,*p,*q;
	e=(elink*)malloc(sizeof(elink));
	e->adj=avex;e->weight=1;e->next=NULL;
	if(head==NULL)
	{
		head=e;
		return head;
	}
	if(head->next==NULL)
	{
		if(head->adj>avex)
		{
			e->next=head;
			return e;
		}
		else
		{
			head->next=e;
			return head;
		}
	}
	if(head->adj>avex)
	{
		e->next=head;
		return e;
	}	
	for(p=head,q=head->next;q->next!=NULL&&q->adj<avex;p=p->next,q=q->next)
	;
	if(q->adj>avex)
	{
	p->next=e;
	e->next=q;
	}
	else
	{
		q->next=e;
	}
	return head;
} 
void DFS(vlink g[],int v)//v代表从那个节点开始访问 
{
	elink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=g[v].link;p!=NULL;p=p->next)
	{
		if(!visited[p->adj]&&g[p->adj].flag==1)
		DFS(g,p->adj);
	}
} 
void BFS(vlink g[],int v)
{
	int front=0,rear=-1;
	int jud;
	elink *p;
	printf("%d ",v);
	visited[v]=1;
	que[++rear]=v;
	while(front<=rear)
	{
		v=que[front++];
		p=g[v].link;
		jud=g[v].flag;
		for(;p!=NULL&&jud==1;p=p->next)
		{
			if(!visited[p->adj]&&g[p->adj].flag==1)
			{
				printf("%d ",p->adj);
				visited[p->adj]=1;
				que[++rear]=p->adj;
			}
		}
	}
}
void start(int dot)
{
	int i;
	for(i=0;i<dot;i++)
	visited[i]=0;
}












