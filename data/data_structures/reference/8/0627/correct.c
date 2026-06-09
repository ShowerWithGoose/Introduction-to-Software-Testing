#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV    256
int visited[256];
int queue[10000];
int front,rear;
typedef struct edge{ 
       int  adj;
       int  wei;
       struct edge *next;
}Elink;
typedef struct ver{
       Elink  *link;
}Vlink;
Vlink  G[MaxV];
Elink  *insert(Elink *head, int avex)
{
    Elink *e,*p,*pre=NULL;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  
	{ 
	return e; 
	}
    for(p=head; p!= NULL&&p->adj<avex;p=p->next)
    {
    	pre=p;
	}
	if(p==head)
	{
		e->next=p;
		return e;
	}
	else{
	    pre->next = e;
	    e->next=p;  
        return head;
	}
}
void DFS(Vlink g[],int v)
{
	Elink *p;
	printf("%d ",v);
	visited[v]=1;
	for(p=g[v].link;p!=NULL;p=p->next)
	{
		if(visited[p->adj]==0)
		{
			DFS(g,p->adj);
		}
	}
}
void BFS(Vlink g[],int v)
{
	Elink *p;
	visited[v]=1;
	front=-1;
	rear=-1;
	queue[++rear]=v;
	while(front!=rear)
	{
		front++;
		v=queue[front];
		printf("%d ",v);
		for(p=g[v].link;p!=NULL;p=p->next)
		{
			if(visited[p->adj]==0)
			{
				visited[p->adj]=1;
				queue[++rear]=p->adj;
			} 
		}
    }
}


int main()
{    
	int m,n,l;
    scanf("%d%d",&m,&n);
    int i,j,k;
    int v1,v2;
    for(i=0;i<n;i++)
    {
    	scanf("%d%d",&v1,&v2);
    	G[v1].link=insert(G[v1].link,v2);
    	G[v2].link=insert(G[v2].link,v1);
	}
	scanf("%d",&l);
	for(i=0;i<m;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<m;i++)
	{
		if(visited[i]==0)
		{
			DFS(G,i);
		}
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<m;i++)
	{
		if(visited[i]==0)
		{
			BFS(G,i);
		}
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		visited[i]=0;
	}
	visited[l]=1;
	for(i=0;i<m;i++)
	{
		if(visited[i]==0)
		{
			DFS(G,i);
		}
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		visited[i]=0;
	}
	visited[l]=1;
	for(i=0;i<m;i++)
	{
		if(visited[i]==0)
		{
			BFS(G,i);
		}
	}
	return 0;
}

