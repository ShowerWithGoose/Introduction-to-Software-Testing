#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct edge{
	int adj;
	struct edge *next;
}Elink;

typedef struct ver{
	Elink *link;
	int cnt;
}Vlink;

Vlink Ga[100];

int Visited[102]={0};
int visit1[102]={0};
int queue[102]={0};
int Q = -1, rear = 0;
	
void DFS(Vlink Ga[],int v);
void BFS(Vlink Ga[],int v);
int main()
{
	int vern,edgen;
	scanf("%d%d",&vern,&edgen);
	int i;
	for(i=0; i<edgen; i++)               // ½¨ÁÚ½Ó±í 
	{
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		Elink *r = (Elink *)malloc(sizeof(Elink));
		r->adj = v2;
		r->next = NULL;
		if(Ga[v1].link == NULL)
		{
			Ga[v1].link = r;
			Ga[v1].cnt++;
		}	
		else 
		{
			Elink *p = Ga[v1].link;
			while( p->next != NULL)
			{
				p = p->next;
			}
			p->next = r;
			Ga[v1].cnt++;
		}
		Elink *q = (Elink *)malloc(sizeof(Elink));
		q->adj = v1;
		q->next = NULL;
		if(Ga[v2].link == NULL)
		{
				Ga[v2].link = q;
				Ga[v2].cnt++;
		}
		else
		{
			Elink *p1 = Ga[v2].link;
			while(p1->next != NULL)
			{
				p1 = p1->next;
			}
			p1->next = q;
			Ga[v2].cnt++;
		}	
	}
	
	for(int ii=0;ii<vern;ii++)
	{
		Elink *u = Ga[ii].link;
		Elink *uu = Ga[ii].link->next;
		Elink *l = Ga[ii].link;
		for(int w1=Ga[ii].cnt-1;w1>0; w1--)
		{
			l = Ga[ii].link;
			for(int w2=0;w2<w1;w2++)
			{
				u = l;
				uu = l->next;
				if(u->adj > uu->adj)
				{
					int temp = u->adj;
					u->adj = uu->adj;
					uu->adj = temp;
				}
				l = l->next;
			}
			
		}
	}
	
	for(int i=0; i<vern; i++)
	{
		if(!Visited[i])
			DFS(Ga,i);
	}
	printf("\n");
	for(int iii=0;iii<vern;iii++)
	{
		if(!visit1[iii])
			BFS(Ga,iii);
	}
	printf("\n");
	int v;
	scanf("%d",&v);
	Elink *p = Ga[v].link;
	for(;p!=NULL;p=p->next)
	{
		int cnt = 0;
		Elink *ii = Ga[p->adj].link;
		Elink *pp = Ga[p->adj].link;
		while(ii->adj != v)
		{
			ii = ii->next;
			cnt++;
		}
		if(0 == cnt)
			Ga[p->adj].link = ii->next;
		else
		{
			for(int jj=0;jj<cnt-1;jj++)
			{
				pp = pp->next;
			}
			pp->next = ii->next;
		}		
	}
	Ga[v].link = NULL;
	for(int k=0;k<vern;k++)
		Visited[k] = 0;
	Visited[v] = 1;
	for(int k=0;k<vern;k++)
	{
		if(!Visited[k])
			DFS(Ga,k);
	}
	printf("\n");
	Q = -1;
	rear = 0;
	
	for(int k=0;k<vern;k++)
	{
		visit1[k] = 0;
		queue[k] = 0;
	}
	visit1[v] = 1;
	for(int k=0;k<vern;k++)
	{
		if(!visit1[k])
			BFS(Ga,k);
	}
		
	
	
	return 0;
}

void DFS(Vlink Ga[],int v)
{
	Elink *p;
	printf("%d ",v);
	Visited[v] = 1;
	for(p = Ga[v].link; p!=NULL; p=p->next)
	{
		if(!Visited[p->adj])
			DFS(Ga,p->adj);
	}
}

void BFS(Vlink Ga[],int v)
{
	Elink *p;
	printf("%d ",v); 
	visit1[v] = 1;
	queue[rear] = v;
	rear++;
	while(Q != rear)
	{
		v = queue[++Q];
		for(p = Ga[v].link; p!= NULL; p = p->next)
		{
			if(!visit1[p->adj])
			{
				printf("%d ",p->adj);
				visit1[p->adj] = 1;
				queue[rear] = p->adj;
				rear++;
			}
		}
	}
}





