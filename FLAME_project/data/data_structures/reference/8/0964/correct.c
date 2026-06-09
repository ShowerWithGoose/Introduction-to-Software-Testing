#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int vist[1000],ans[1000];
int potnum,edgenum;
typedef struct a{
	int ad;
	struct a *next;
}edges;
typedef struct b{
	int ad;
	edges *link;
}head; 
edges* insert (edges* link,int ad)
{
	edges *p,*q,*m;
	p=link;
	if(p==NULL)
	{
		p=(edges *)malloc(sizeof(edges));
		p->ad=ad;
		p->next=NULL;
		return p;
	}
	int first=0;
	for(q=p;p!=NULL;p=q->next)
	{
		if(first==0)
		{
			if(p->ad>ad)
			{
				m=(edges *)malloc(sizeof(edges));
				m->ad=ad;
				m->next=p;
				return m;
			}
			first=1;
			continue;
		}
		if(p->ad>ad)
		{
			m=(edges *)malloc(sizeof(edges));
			m->ad=ad;
			m->next=p;
			q->next=m;
			return link;
		}
		q=q->next;
	}
	m=(edges *)malloc(sizeof(edges));
	m->ad=ad;
	m->next=NULL;
	q->next=m;
	return link;
}
void DFS(head vers[],int pot,int no)
{
	edges *p;
	vist[pot]=1;
	printf("%d ",pot);
	for(p=vers[pot].link;p!=NULL;p=p->next)
	{
		if(p->ad==no)
		continue;
		else if(!vist[p->ad])
		DFS(vers,p->ad,no);
	}
}
void trDFS(head vers[],int no)
{
	int i;
	memset(vist,0,sizeof(vist));
	for(i=0;i<potnum;i++)
	{
		if(i==no)
		continue;
		if(!vist[i])
		DFS(vers,i,no);
	}
	printf("\n");
}
void trBFS(head vers[],int no)
{
	int stack[1000],rear=0,front=-1;
	stack[++front]=0;
	memset(vist,0,sizeof(vist));
	while(front>=rear)
	{
		head p=vers[stack[rear++]];
		vist[p.ad]=1;
		printf("%d ",p.ad);
		edges *q;
		for(q=p.link;q!=NULL;q=q->next)
		{
			if(q->ad==no)
			continue;
			if(vist[q->ad]==0)
			{
				stack[++front]=q->ad;
				vist[q->ad]=1;
			}
		}
	}
	printf("\n");
}
int main()
{
	head vers[1000];
	scanf("%d %d",&potnum,&edgenum);
	int i=0,he,ad,no;
	for(i=0;i<edgenum;i++)
	vers[i].link=NULL;
	for(i=0;i<edgenum;i++)
	{
		scanf("%d %d",&he,&ad);
		vers[he].ad=he,vers[ad].ad=ad;
		vers[he].link=insert(vers[he].link,ad);
		vers[ad].link=insert(vers[ad].link,he);
	}
	scanf("%d" ,&no);
	trDFS(vers,edgenum);
	trBFS(vers,edgenum);
	trDFS(vers,no);
	trBFS(vers,no);
	return 0;
}



