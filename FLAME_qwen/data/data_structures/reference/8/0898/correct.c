#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
int queue[20000] = { 0 };
typedef struct edge {
	int adjvex;
	int weight;
	struct edge* next;
}ELink,*ek;
typedef struct ver {
	int a;
	ELink* link;
}VLink,*vk;
VLink G[200];
int IsUsed[200];
void Insert(int a, int b)
{
	ek p = NULL;
	p = (ek)malloc(sizeof(ELink));
	p->adjvex = b;
	p->weight = 0;
	p->next = NULL;
	ek q = G[a].link;
	if (G[a].link == NULL)
	{
		G[a].link = p;
		return;
	}
	if (G[a].link->next == NULL)
	{
		if (G[a].link->adjvex > p->adjvex)
		{
			ek k = G[a].link;
			G[a].link = p;
			p->next = k;
		}
		else
		{
			G[a].link->next= p;
		}
		return;
	}
	ek m = q;
	if (m->adjvex > p->adjvex)
	{
		G[a].link = p;
		p->next = m;
		return;
	}
	q = q->next;
	while (q!= NULL)
	{
		if (m->adjvex<p->adjvex && q->adjvex>p->adjvex)
		{
			m->next = p;
			p->next = q;
			return;
		}
		m = q;
		q = q->next;
	}
		m->next = p;
}
void dfs(int v)
{
	ELink* p = NULL;
	IsUsed[v] = 1;
	printf("%d ", v);
	for (p = G[v].link;p != NULL;p = p->next)
	{
		if (IsUsed[p->adjvex] != 1)
			dfs(p->adjvex);
	}
}
void bfs(int v)
{
	int pb = 0;
	int pd = 0;
	ek p = G[0].link;
	queue[pd] = 0;
	pd++;
	while (pb != pd)
	{
		int a = queue[pb];
		ek p = G[a].link;
		while (p != NULL)
		{
			if (IsUsed[p->adjvex] != 1)
			{
				queue[pd] = p->adjvex;
				IsUsed[p->adjvex] = 1;
				pd++;
			}
			p = p->next;
		}
		printf("%d ", queue[pb]);
		IsUsed[queue[pb]] = 1;
		pb++;
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		Insert(a,b);
		Insert(b,a);
	}
	int num = 0;
	scanf("%d", &num);
	dfs(0);
	printf("\n");
	memset(IsUsed, 0, 200);
	bfs(0);
	printf("\n");
	memset(IsUsed, 0, 200);
	memset(queue, 0, 20000);
	IsUsed[num] = 1;
	dfs(0);
	printf("\n");
	memset(IsUsed, 0, 200);
	IsUsed[num] = 1;
	bfs(0);
	printf("\n");
	memset(IsUsed, 0, 200);
}

