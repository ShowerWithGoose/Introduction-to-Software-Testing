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
int Visit[120];
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
	int pai[120]={0},i,j;
	visit(v);
	Visit[v]=1;
	for(p=tu[v].link,i=0;p!=NULL;p=p->next,i++)pai[i]=p->adjvex;
	qsort(pai,i,sizeof(pai[0]),cmp);
	for(j=0;j<i;j++)
		if(Visit[pai[j]]==0)DFS(pai[j]);
}
void BFS()
{
	ELink *p;
	int queue[120],i,j,pai[120]={0},k,h;
	queue[0]=tu[0].vertex;
	i=0;
	j=0;
	while(i<=j)
	{
		if(Visit[queue[i]]==0)
			visit(queue[i]);
		Visit[queue[i]]=1;
		for(p=tu[queue[i]].link,k=0;p!=NULL;p=p->next,k++)pai[k]=p->adjvex;
		qsort(pai,k,sizeof(pai[0]),cmp);
		for(h=0;h<k;h++)
			if(Visit[pai[h]]==0)queue[++j]=pai[h];
		i++;
	}
}
int main()
{
	int dian,bian,i,j,k,del;
	ELink *p,*q,*f;
	scanf("%d%d",&dian,&bian);
	for(i=0;i<dian;i++)tu[i].vertex=i;
	for(i=0;i<bian;i++)
	{
		scanf("%d%d",&j,&k);
		p=(ELink*)malloc(sizeof(ELink));
		p->adjvex=k;p->next=NULL;
		if(tu[j].link==NULL)
		tu[j].link=p;
		else 
		{
			q=tu[j].link;
			while(q->next!=NULL)q=q->next;
			q->next=p;
		}
		p=(ELink*)malloc(sizeof(ELink));
		p->adjvex=j;p->next=NULL;
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
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	BFS();
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	scanf("%d",&del);	
	for(p=tu[del].link;p!=NULL;p=p->next)
	{
		j=p->adjvex;
		for(q=tu[j].link,f=q;q->adjvex!=del;q=q->next)f=q;
		if(f!=q)
			f->next=q->next;
		else 
			tu[j].link=q->next;
	}
	DFS(0);
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	BFS();
	memset(Visit,0,sizeof(Visit));
	printf("\n");
	return 0;
}



