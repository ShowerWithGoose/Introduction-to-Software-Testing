#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct edge{
	int ad;
	struct edge *next;
}ELink;
typedef struct ver{
	ELink *link;
}VLink;
VLink G[150];
int vis[150];
int del=-1;
void DFS(VLink G[],int v)
{
	ELink *p;
	vis[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(p->ad==del)
			continue;
		if(!vis[p->ad])
			DFS(G,p->ad);
	}
}
void travelDFS(VLink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
		vis[i]=0;
	for(i=0;i<n;i++)
	{
		if(i==del)
			continue;
		if(!vis[i])
			DFS(G,i);
	}
}
int first=-1,rear=-1,queue[150];
void BFS(VLink G[],int v)
{
	ELink *p;
	vis[v]=1;
	queue[++rear]=v;
	while(first<rear)
	{
		v=queue[++first];
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			if(p->ad==del)
				continue;
			if(!vis[p->ad])
			{
				vis[p->ad]=1;
				queue[++rear]=p->ad;
			}
		}
	}
}
void travelBFS(VLink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
		vis[i]=0;
	for(i=0;i<n;i++)
	{
		if(i==del)
			continue;
		if(!vis[i])
			BFS(G,i);
	} 
}
int main()
{
	int dnum,bnum,i;
	scanf("%d%d",&dnum,&bnum);
	for(i=0;i<dnum;i++)
		G[i].link=NULL;
	for(i=0;i<bnum;i++)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		ELink *e,*p,*h;
		e=(ELink*)malloc(sizeof(ELink));
		e->ad=n;
		e->next=NULL;
		if(G[m].link==NULL)
			G[m].link=e;
		else
		{
			p=G[m].link;
			while(p!=NULL&&p->ad<e->ad)
			{
				h=p;
				p=p->next;
			}
			if(p==NULL)
				h->next=e;
			else if(G[m].link->ad>e->ad)
			{
			    e->next=p;
			    G[m].link=e;
			}
			else
			{
				h->next=e;
				e->next=p;
			}
		}
		e=(ELink*)malloc(sizeof(ELink));
		e->ad=m;
		e->next=NULL;
		if(G[n].link==NULL)
			G[n].link=e;
		else
		{
			p=G[n].link;
			while(p!=NULL&&p->ad<e->ad)
			{
				h=p;
				p=p->next;
			}
			if(p==NULL)
				h->next=e;
			else if(G[n].link->ad>e->ad)
			{
			    e->next=p;
			    G[n].link=e;
			}
			else
			{
				h->next=e;
				e->next=p;
			}
		}
	}
	travelDFS(G,dnum);
	printf("\n");
	travelBFS(G,dnum);
	printf("\n");
	scanf("%d",&del);
	travelDFS(G,dnum);
		printf("\n");
	travelBFS(G,dnum);
	return 0; 
} 

