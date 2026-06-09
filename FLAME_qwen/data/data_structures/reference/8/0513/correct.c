#include<stdio.h>
#include<malloc.h>
typedef struct elink
{
	int adjvex;
	struct elink* next;
}elink;
typedef struct vlink
{
	elink *link;
}vlink;
vlink G[105];
int visited[105];
int queue[200];
int front=0,rear=0;
void insert(vlink G[],int v1,int v2)
{
	elink* new1=(elink*)malloc(sizeof(elink));
	elink* new2=(elink*)malloc(sizeof(elink));
	new1->next=new2->next=NULL,new1->adjvex=v2,new2->adjvex=v1;
	elink* p=G[v1].link,*r;
	if(p==NULL)
	{
		G[v1].link=new1;
	}
	else
	{
	    if(p->adjvex>v2)
	    {
	    	new1->next=G[v1].link;
	    	G[v1].link=new1;
		}
		else
		{
		   while(p&&p->adjvex<v2)
	        {
		        r=p,p=p->next;
	        }
		    new1->next=p,r->next=new1;				
		}
	}
	p=G[v2].link;
	if(p==NULL)
	{
		G[v2].link=new2;
	}
	else
	{
		if(p->adjvex>v1)
		{
			new2->next=G[v2].link;
			G[v2].link=new2;
		}
		else
		{
			while(p&&p->adjvex<v1)
		    {
			    r=p,p=p->next;
		    }
		    new2->next=p,r->next=new2;
		}

	}
}
void DFS(vlink G[],int v)
{
	visited[v]=1;
	printf("%d ",v);
	for(elink *p=G[v].link;p!=NULL;p=p->next)
	{
		if(!visited[p->adjvex])
		{
			DFS(G,p->adjvex);
		}
	}
}
void travelDFS(vlink G[],int V)
{

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		DFS(G,i);
	}
	putchar('\n');
}
void BFS(vlink G[],int v)
{
	visited[v]=1;
	queue[rear++]=v;
	while(front<rear)
	{
		v=queue[front++];
		printf("%d ",v);
		elink *p=G[v].link;
		for(;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex]=1;
				queue[rear++]=p->adjvex;
			}
		}
	}
}
void travelBFS(vlink G[],int V)
{

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			BFS(G,i);
		}
	}
	putchar('\n');
}
int main()
{
	int V=0,E=0;
	scanf("%d%d",&V,&E);
	for(int i=0;i<V;i++)
	{
		G[i].link=NULL;
	}
	for(int i=0;i<E;i++)
	{
		int v1=0,v2=0;
		scanf("%d%d",&v1,&v2);
		insert(G,v1,v2);
	}
	travelDFS(G,V);
	for(int i=0;i<V;i++)
	{
		visited[i]=0;
	}
	travelBFS(G,V);
	int todel;
	scanf("%d",&todel);
	for(int i=0;i<V;i++)
	{
		visited[i]=0;
	}
	visited[todel]=1;
	travelDFS(G,V);
	for(int i=0;i<V;i++)
	{
		visited[i]=0;
	}
	visited[todel]=1;
	travelBFS(G,V);
	return 0;
}


