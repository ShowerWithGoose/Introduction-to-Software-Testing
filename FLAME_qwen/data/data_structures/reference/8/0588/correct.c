#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 105

typedef struct edge{
	int adjvex;
	struct edge *next;
}ELink;
typedef struct ver{
	int vertex;
	ELink* link;
}VLink;
VLink G[MAXV];
int isVisited[MAXV] = {0};
int Queue[MAXV];
int Front = 0,Rear = -1;

void createGraph(int m,int b);
void travelDFS(VLink G[],int n);
void DFS(VLink G[],int v);
void travelBFS(VLink G[],int n);
void BFS(VLink G[],int v);
void delvex(int a,int m);

int main()
{
	int i=0,j=0;
	int m,n,a,b;
	ELink* p;
	scanf("%d%d",&m,&n);
	b=n;
	for(i=0;i<m;i++)
	{
		G[i].vertex = i;
		G[i].link = NULL;
	}
	//初始化结点数组
	
	createGraph(m,b);
	
	memset(isVisited,0,sizeof(isVisited));
	travelDFS(G,m);
	printf("\b\n");
	
	memset(isVisited,0,sizeof(isVisited));
	travelBFS(G,m);
	printf("\b\n");
	
	scanf("%d",&a);
	delvex(a,m);
	
	memset(isVisited,0,sizeof(isVisited));
	isVisited[a]=1;
	travelDFS(G,m);
	printf("\b\n");
	
	memset(isVisited,0,sizeof(isVisited));
	isVisited[a]=1;
	travelBFS(G,m);
	printf("\b\n");
	
	return 0;
	
}

void createGraph(int m,int b)
{
	int a1,a2;
	ELink* p,*p0,*q;
	while(b--)
	{
		scanf("%d%d",&a1,&a2);
		q = (ELink*)malloc(sizeof(ELink));
		q->adjvex = a2;
		q->next=NULL;
		
		for(p0=p=G[a1].link;p;p0=p,p=p->next)
		{
			if(p->adjvex > q->adjvex)
			{
				if(p==G[a1].link)
				{
					q->next = p;
					G[a1].link = q;
					break;
				}
				else{
					q->next = p0->next;
					p0->next = q;
					break;
				}
			}
		}
		if(G[a1].link==NULL)
			G[a1].link = q;
		else if(p==NULL)
		p0->next = q;
		
		q=(ELink*)malloc(sizeof(ELink));
		q->adjvex = a1;
		q->next = NULL;
		
		for(p0=p=G[a2].link;p;p0=p,p=p->next)
		{
			if(p->adjvex > q->adjvex)
			{
				if(p==G[a2].link)
				{
					q->next = p;
					G[a2].link = q;
					break;
				}
				else
				{
					q->next = p0->next;
					p0->next = q;
					break;
				}
			}
		}
		if(G[a2].link ==NULL )
			G[a2].link = q;
		else if(p==NULL)
			p0->next = q;
	}
}

void travelDFS(VLink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(!isVisited[i])
			DFS(G,i);
	return;
}

void DFS(VLink G[],int v)
{
	ELink *p;
	isVisited[v]=1;
	printf("%d ",v);
	for(p = G[v].link;p!=NULL;p=p->next)
		if(!isVisited[p->adjvex])
			DFS(G,p->adjvex);
	return;
}

void travelBFS(VLink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(!isVisited[i])
			BFS(G,i);
	return;
}

void BFS(VLink G[],int v)
{
	ELink* p;
	isVisited[v] = 1;
	Queue[++Rear]=v;
	while(Front<=Rear){
		v=Queue[Front++];
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next)
			if(!isVisited[p->adjvex]){
			isVisited[p->adjvex] = 1;
			Queue[++Rear] = p->adjvex;
		}
	}
	
	return;
}

void delvex(int a,int m)
{
	int i;
	ELink* p,*p0;
	G[a].link = NULL;
	
	for(i=0;i<m;i++)
	{
		for(p0=p=G[i].link;p;p0=p,p=p->next)
		{
			if(p->adjvex == a)
			{
				if(p==G[i].link)
					G[i].link = p->next;
				else
					p0->next = p->next;
				break;
			}
		}
		
	}
	return;
}

