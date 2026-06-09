#pragma GCC optimize(3)

#include <stdio.h>
#include <stdlib.h>
typedef struct TU
{
	int jie;
	int li;
	struct LIAN *link;
} tu;
typedef struct LIAN
{
	int xiang;
	struct LIAN *link;
} lian;
tu *a[100];
int c = 0, d = 0, b[100];
int main()
{
	int n, m, i, j, k, l = 0, z;

	lian *q, *p, *r, *o;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		a[i] = (tu *)malloc(sizeof(tu));
		a[i]->link = NULL;
		a[i]->jie = i;
		a[i]->li = 0;
	}
	for (i = 0; i < m; i++)
	{
		o = NULL;
		l = 0;
		scanf("%d %d", &j, &k);
		q = (lian *)malloc(sizeof(lian));
		q->xiang = k;
		q->link = NULL;
		r = (lian *)malloc(sizeof(lian));
		r->xiang = j;
		r->link = NULL;
		if (a[j]->link == NULL)
		{
			a[j]->link = q;
		}
		else
		{
			for (p = a[j]->link; p != NULL && k > p->xiang; o = p, p = p->link)
				;
			if (p == a[j]->link)
			{
				a[j]->link = q;
				q->link = p;
			}
			else
			{
				o->link = q;
				q->link = p;
			}
		}
		if (a[k]->link == NULL)
		{
			a[k]->link = r;
		}
		else
		{
			for (p = a[k]->link; p != NULL && j > p->xiang; o = p, p = p->link)
				;
			if (p == a[k]->link)
			{
				a[k]->link = r;
				r->link = p;
			}
			else
			{
				o->link = r;
				r->link = p;
			}
		}
	}
	scanf("%d", &z);
	DFS(a, 0);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		a[i]->li = 0;
	}
	BFS(a, 0);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		a[i]->li = 0;
	}
	a[z]->li = 1;
	DFS(a, 0);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		a[i]->li = 0;
	}
	a[z]->li = 1;
	BFS(a, 0);
	/*for(i=0;i<n;i++)
	{
		printf("\n%d ",i);
		if(a[i]->link!=NULL)
		{

		for(p=a[i]->link;p!=NULL;p=p->link)
			{
				printf("%d ",p->xiang);
			}
		}
	}*/
	return 0;
}
void DFS(tu *t[], int v)
{
	lian *p;
	a[v]->li = 1;
	printf("%d ", a[v]->jie);
	for (p = a[v]->link; p != NULL; p = p->link)
	{
		if (!a[p->xiang]->li)
		{
			DFS(t, p->xiang);
		}
	}
}
void BFS(tu t[], int v)
{
	lian *p;
	a[v]->li = 1;
	b[d] = a[v]->jie;
	d++;
	while (c != d)
	{
		v = b[c];
		c++;
		printf("%d ", a[v]->jie);
		for (p = a[v]->link; p != NULL; p = p->link)
		{
			if (!a[p->xiang]->li)
			{
				a[p->xiang]->li = 1;
				b[d] = a[p->xiang]->jie;
				d++;
			}
		}
	}
}

