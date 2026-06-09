#include<stdio.h>
#include<stdlib.h>

typedef struct edge{
	int adjvex;
	struct edge *next;
}elink;
typedef struct ver{
	int vertex;
	elink *link;
}vlink;
vlink G[102];
int que[102]={0};
int qst=0,qlt=0;
int cmp(const void *p1,const void *p2){
	return (*((int*)p1)-*((int*)p2));
}
elink *insert(elink *head,int avex)
{
	elink *e,*p;
	e=(elink*)malloc(sizeof(elink));
	e->adjvex=avex;
	e->next=NULL;
	if(head==NULL)
	{ 
		head=e;
		return head;
	 } 
	 for(p=head;p->next!=NULL;p=p->next);
	 p->next=e;
	 return head;
}

void DFS(vlink G[],int visited[],int v)
{
	elink *p;
	visited[v]=1;
	printf("%d ",G[v].vertex);
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(!visited[p->adjvex]) DFS(G,visited,p->adjvex);
	}	
}


void dDFS(vlink G[],int visited[],int v,int del)
{
	elink *p;
	visited[v]=1;
	printf("%d ",G[v].vertex);
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(!visited[p->adjvex]&&p->adjvex!=del) dDFS(G,visited,p->adjvex,del);
	}	
}

void BFS(vlink G[],int visited[],int v)
{
	elink *p;
	visited[v]=1;
	que[qlt]=v;
	qlt++;
	while(qlt!=qst)
	{
		v=que[qst];
		qst++;
		printf("%d ",G[v].vertex);
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex]=1;
				que[qlt]=G[p->adjvex].vertex;
				qlt++;
			}
		}
	}
	
}

void dBFS(vlink G[],int visited[],int v,int del)
{
	elink *p;
	visited[v]=1;
	que[qlt]=v;
	qlt++;
	while(qlt!=qst)
	{
		v=que[qst];
		qst++;
		printf("%d ",G[v].vertex);
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex]&&p->adjvex!=del)
			{
				visited[p->adjvex]=1;
				que[qlt]=G[p->adjvex].vertex;
				qlt++;
			}
		}
	}
	
}

int main()
{
	int lnum,dnum,a1,a2,del;
	scanf("%d%d",&dnum,&lnum);
	int i,j,k;
	int visited[102];
	vlink *p;
	elink *e;
	for(i=0;i<dnum;i++)
	{
		G[i].vertex=i;
	}
	for(i=0;i<lnum;i++)
	{
		scanf("%d%d",&a1,&a2);
		G[a1].link=insert(G[a1].link,a2);
		G[a2].link=insert(G[a2].link,a1);
	}
	scanf("%d",&del);
	int temp[20];
	for(i=0;i<dnum;i++)
	{
		k=0;
		e=G[i].link;
		while(e!=NULL)
		{
			temp[k]=e->adjvex;
			k++;
			e=e->next;
		}
		qsort(temp,k,sizeof(int),cmp);
		e=G[i].link;
		for(j=0;j<k;j++)
		{
			e->adjvex=temp[j];
			e=e->next;
		}
	}
	for(i=0;i<102;i++)  visited[i]=0;
	DFS(G,visited,0);
	printf("\n");
	for(i=0;i<102;i++)  visited[i]=0;
	BFS(G,visited,0);
	printf("\n");
	for(i=0;i<102;i++)  visited[i]=0;
	dDFS(G,visited,0,del);
	printf("\n");
	for(i=0;i<102;i++)  visited[i]=0;
	dBFS(G,visited,0,del);
	return 0;
}

