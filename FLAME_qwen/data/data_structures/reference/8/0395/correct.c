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

Vlink G[100];

int visit[102]={0};
int visit1[102]={0};
int queue[102]={0};
int top = -1, rear = 0;
	
void DFS(Vlink G[],int v);
void BFS(Vlink G[],int v);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=0; i<m; i++)               // ½¨ÁÚ½Ó±í 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Elink *r = (Elink *)malloc(sizeof(Elink));
		r->adj = y;
		r->next = NULL;
		if(G[x].link == NULL)
		{
			G[x].link = r;
			G[x].cnt++;
		}	
		else 
		{
			Elink *p = G[x].link;
			while( p->next != NULL)
			{
				p = p->next;
			}
			p->next = r;
			G[x].cnt++;
		}
		Elink *q = (Elink *)malloc(sizeof(Elink));
		q->adj = x;
		q->next = NULL;
		if(G[y].link == NULL)
		{
				G[y].link = q;
				G[y].cnt++;
		}
		else
		{
			Elink *p1 = G[y].link;
			while(p1->next != NULL)
			{
				p1 = p1->next;
			}
			p1->next = q;
			G[y].cnt++;
		}	
	}
	
	for(int t=0;t<n;t++)
	{
		Elink *u = G[t].link;
		Elink *uu = G[t].link->next;
		Elink *l = G[t].link;
		for(int w1=G[t].cnt-1;w1>0; w1--)
		{
			l = G[t].link;
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
	
	for(int i=0; i<n; i++)
	{
		if(!visit[i])
			DFS(G,i);
	}
	printf("\n");
	for(int j=0;j<n;j++)
	{
		if(!visit1[j])
			BFS(G,j);
	}
	printf("\n");
	int op;
	scanf("%d",&op);
	Elink *p = G[op].link;
	for(;p!=NULL;p=p->next)
	{
		int cnt = 0;
		Elink *ii = G[p->adj].link;
		Elink *pp = G[p->adj].link;
		while(ii->adj != op)
		{
			ii = ii->next;
			cnt++;
		}
		if(0 == cnt)
			G[p->adj].link = ii->next;
		else
		{
			for(int jj=0;jj<cnt-1;jj++)
			{
				pp = pp->next;
			}
			pp->next = ii->next;
		}		
	}
	G[op].link = NULL;
	for(int k=0;k<n;k++)
		visit[k] = 0;
	visit[op] = 1;
	for(int k=0;k<n;k++)
	{
		if(!visit[k])
			DFS(G,k);
	}
	printf("\n");
	top = -1;
	rear = 0;
	
	for(int k=0;k<n;k++)
	{
		visit1[k] = 0;
		queue[k] = 0;
	}
	visit1[op] = 1;
	for(int k=0;k<n;k++)
	{
		if(!visit1[k])
			BFS(G,k);
	}
		
	
	
	return 0;
}

void DFS(Vlink G[],int v)
{
	Elink *p;
	printf("%d ",v);
	visit[v] = 1;
	for(p = G[v].link; p!=NULL; p=p->next)
	{
		if(!visit[p->adj])
			DFS(G,p->adj);
	}
}

void BFS(Vlink G[],int v)
{
	Elink *p;
	printf("%d ",v); 
	visit1[v] = 1;
	queue[rear] = v;
	rear++;
	while(top != rear)
	{
		v = queue[++top];
		for(p = G[v].link; p!= NULL; p = p->next)
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





