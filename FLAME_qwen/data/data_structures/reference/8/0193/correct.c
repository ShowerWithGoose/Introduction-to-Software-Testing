#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

typedef struct edge{
	int adjvex;
	struct edge *next;
}Elink;

typedef struct ver{
	Elink *link;
}Vlink;

Vlink G[200];
int flag[200];
int quene[1000];
int front=0,rear=999,count=0;

Elink* develop(Elink *head,int num);
void TRAVEL_DFS(Vlink G[],int n,int ope);
void DFS(Vlink G[],int v);
void TRAVEL_BFS(Vlink G[],int n,int ope);
void BFS(Vlink G[],int v);
void ru(int num);
int chu();
int isempty();

int main()
{
	int a,b,i,v1,v2;
	Elink *p,*q;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++)
	{
		G[i].link=NULL;
	}
	while(b--)
	{
		scanf("%d %d",&v1,&v2);
		G[v1].link=develop(G[v1].link,v2);
		G[v2].link=develop(G[v2].link,v1);
	}
	TRAVEL_DFS(G,a,-1);
	TRAVEL_BFS(G,a,-1);
	scanf("%d",&v1);
	TRAVEL_DFS(G,a,v1);
	TRAVEL_BFS(G,a,v1);
	return 0;
 }
 
Elink *develop(Elink *head,int num)
{
	Elink *m,*p,*q;
	p=(Elink *)malloc(sizeof(Elink));
	p->adjvex=num;
	p->next=NULL;
	if(head==NULL)
	{
		return p;
	}
	for(m=head;m!=NULL&&num>m->adjvex;q=m,m=m->next);
	if(m==head)
	{
		p->next=m;
		return p;
	}
	q->next=p;
	p->next=m;
	return head;
}
 
void TRAVEL_DFS(Vlink G[],int n,int ope)
{
	int i;
	for(i=0;i<n;i++)
	{
		flag[i]=0;
	}
	if(ope>=0)
	{
		flag[ope]=1;
	}
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			DFS(G,i);
		}
	}
	printf("\n");
 } 
 
void DFS(Vlink G[],int v)
{
	Elink *p;
	printf("%d ",v);
	flag[v]=1;
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(flag[p->adjvex]==0)
		{
			DFS(G,p->adjvex);
		}
	}
}

void TRAVEL_BFS(Vlink G[],int n,int ope)
{
	int i;
	for(i=0;i<n;i++)
	{
		flag[i]=0;
	}
	if(ope>=0)
	{
		flag[ope]=1;
	}
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			BFS(G,i);
		}
	}
	printf("\n");
}

void BFS(Vlink G[],int v)
{
	Elink  *p;
	flag[v]=1;
	ru(v);
	while(isempty()==0)
	{
		v=chu();
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			if(flag[p->adjvex]==0)
			{
				flag[p->adjvex]=1;
				ru(p->adjvex);
			}
		}
	}
}

void ru(int num)
{
	rear=(rear+1)%1000;
	quene[rear]=num;
	count++;
}

int chu()
{
	int x;
	count--;
	x=quene[front];
	front=(front+1)%1000;
	return x; 
}

int isempty()
{
	return count==0;
}

