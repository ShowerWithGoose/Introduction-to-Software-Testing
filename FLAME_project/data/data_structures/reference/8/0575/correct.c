#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct Vtype
{
	struct Etype* next;
}v[105];

struct Etype
{
	int vend;
	struct Etype* next;
};

int went[105] = { 0 }, wentwide[105] = { 0 };

void build(int v1, int v2)
{
	struct Etype* p = v[v1].next, * q;
	if (p == NULL)
	{
		q = (struct Etype*)malloc(sizeof(struct Etype));
		q->vend = v2;
		q->next = NULL;	
		v[v1].next = q;
		return;
	}
	else if (p->vend > v2)
	{
		q = (struct Etype*)malloc(sizeof(struct Etype));
		q->vend = v2;
		q->next = p;
		v[v1].next = q;
		return;
	}
	else
	{
		while (p->next != NULL && p->next->vend < v2)
		{
			p = p->next;
		}
		q = (struct Etype*)malloc(sizeof(struct Etype));
		q->vend = v2;
		q->next = p->next;
		p->next = q;
		return;
	}
}

void delate(int n)
{
	int m;
	struct Etype* p = v[n].next, * q, * r;
	while (p != NULL)
	{
		m = p->vend;
		q = v[m].next;
		if (q->vend == n)
		{
			v[m].next = q->next;
			free(q);
		}
		else
		{
			while (q->next->vend != n)
			{
				q = q->next;
			}
			r = q->next;
			q->next = q->next->next;
			free(r);
		}
		p = p->next;
	}
	v[n].next = NULL;
	return;
}

void deep(int n)
{
	printf("%d ", n);
	went[n] = 1;
	struct Etype* p=v[n].next;
	while (p != NULL)
	{
		if (went[p->vend] == 0)
		{
			deep(p->vend);
		}
		p = p->next;
	}
	return;
}

int list[105], l = 1, k = 0;

int V;

void wide(int n)
{
	wentwide[n] = 1;
	printf("%d ", n);
	struct Etype* p = v[n].next;
	while (p != NULL)
	{
		if (wentwide[p->vend] == 0)
		{
			wentwide[p->vend] = 1;
			list[l] = p->vend;
			l++;
		}
		p = p->next;
	}
	k = k + 1;
	if (k < V)
	{
		wide(list[k]);
	}
	return;
}

int main()
{
	for (int i = 0; i < 105; i++)
	{
		v[i].next = NULL;
	}
	int e,v1,v2,vdelate;
	scanf("%d %d", &V, &e);
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d", &v1, &v2);
		build(v1, v2);
		build(v2, v1);
	}
	/*
	struct Etype* p;
	for (int i = 0; i < V; i++)
	{
		printf("%d : ", i);
		p = v[i].next;
		for (; p != NULL; p = p->next)
		{
			printf("%d ", p->vend);
		}
		printf("\n");
	}
	*/
	wentwide[0] = 1;
	deep(0);
	printf("\n");
	wide(0);
	printf("\n");
	memset(went, 0, sizeof(went));
	memset(wentwide, 0, sizeof(wentwide));
	memset(list, 0, sizeof(list)); 
	l = 1;
	k = 0;
	V = V - 1;
	scanf("%d", &vdelate);
	delate(vdelate);
	struct Etype* p;
	/*
	for (int i = 0; i < V; i++)
	{
		printf("%d : ", i);
		p = v[i].next;
		for (; p != NULL; p = p->next)
		{
			printf("%d ", p->vend);
		}
		printf("\n");
	}
	*/
	deep(0);
	printf("\n");
	wide(0);
	return 0;
}
