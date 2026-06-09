#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
typedef struct edge
{
	int adjvex;
	struct edge *next;
}ELink;
typedef struct ver
{
	int vertex;
	ELink *link;
}VLink;
VLink tu[120];
int jilu[120];
int cmp(const void*a,const void*b)
{
	int *x=(int*)a;
	int *y=(int*)b;
	return *x-*y;
}
void visit(int x)
{
	printf("%d ",tu[x].vertex);
}
void DFS(int v)
{
	ELink *p;
	int pai[120]={0},i,n;
	visit(v);
	jilu[v]=1;
	for(p=tu[v].link,i=0;p!=NULL;p=p->next,i++)pai[i]=p->adjvex;
	qsort(pai,i,sizeof(pai[0]),cmp);
	for(n=0;n<i;n++)
		if(jilu[pai[n]]==0)DFS(pai[n]);
}
void BFS()
{
	ELink *p;
	int queue[120],i,n,pai[120]={0},k,h;
	queue[0]=tu[0].vertex;
	i=0;
	n=0;
	while(i<=n)
	{
		if(jilu[queue[i]]==0)
			visit(queue[i]);
		jilu[queue[i]]=1;
		for(p=tu[queue[i]].link,k=0;p!=NULL;p=p->next,k++)pai[k]=p->adjvex;
		qsort(pai,k,sizeof(pai[0]),cmp);
		for(h=0;h<k;h++)
			if(jilu[pai[h]]==0)queue[++n]=pai[h];
		i++;
	}
}
int main()
{
	int d,b,i,n,k,a;
	ELink *p,*q,*f;
	scanf("%d%d",&d,&b);
	for(i=0;i<d;i++)tu[i].vertex=i;
	for(i=0;i<b;i++)
	{
		scanf("%d%d",&n,&k);
		p=(ELink*)malloc(sizeof(ELink));
		p->adjvex=k;p->next=NULL;
		if(tu[n].link==NULL)
		tu[n].link=p;
		else 
		{
			q=tu[n].link;
			while(q->next!=NULL)q=q->next;
			q->next=p;
		}
		p=(ELink*)malloc(sizeof(ELink));
		p->adjvex=n;p->next=NULL;
		if(tu[k].link==NULL)tu[k].link=p;
		else 
		{
			q=tu[k].link;
			while(q->next!=NULL)q=q->next;
			q->next=p;
		}
	}
//	for(i=0;i<dian;i++)
//	{
//		for(p=tu[i].link;p!=NULL;p=p->next)printf("%d ",p->adjvex);
//		printf("\n");
//	}
	DFS(0);
	memset(jilu,0,sizeof(jilu));
	printf("\n");
	BFS();
	memset(jilu,0,sizeof(jilu));
	printf("\n");
	scanf("%d",&a);	
	for(p=tu[a].link;p!=NULL;p=p->next)
	{
		n=p->adjvex;
		for(q=tu[n].link,f=q;q->adjvex!=a;q=q->next)f=q;
		if(f!=q)
			f->next=q->next;
		else 
			tu[n].link=q->next;
	}
	DFS(0);
	memset(jilu,0,sizeof(jilu));
	printf("\n");
	BFS();
	memset(jilu,0,sizeof(jilu));
	printf("\n");
	return 0;
}



