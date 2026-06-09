#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUILD_LIST_NODE_STRUCTURE(type, nodename) \
typedef struct _list_node \
{ \
	struct _list_node *prev; \
	struct _list_node *next; \
	type v; \
}nodename;
#define BUILD_LIST_FUN_DEFS(type, nodename) \
nodename *new_##nodename(type v); \
void delete_##nodename(nodename *p); \
void insert_##nodename(nodename *pr, nodename *p);
#define BUILD_LIST_FUNS(type, nodename) \
nodename *new_##nodename(type v) \
{ \
	nodename *p; \
	p = (nodename *)malloc(sizeof(nodename)); \
	p->v = v; \
	return p; \
} \
void delete_##nodename(nodename *p) \
{ \
	p->prev->next = p->next; \
	p->next->prev = p->prev; \
} \
void insert_##nodename(nodename *pr, nodename *p) \
{ \
	p->prev = pr; \
	p->next = pr->next; \
	pr->next->prev = p; \
	pr->next = p; \
}
#define LIST_NEW(nodename, v) new_##nodename(v)
#define LIST_DELETE(nodename, p) delete_##nodename(p)
#define LIST_INSERT(nodename, pr, p) insert_##nodename(pr, p)

typedef struct
{
	int a;
	int n;
}ITEM;
BUILD_LIST_NODE_STRUCTURE(ITEM, LIST_NODE)

BUILD_LIST_FUN_DEFS(ITEM, LIST_NODE)

LIST_NODE *head, *tail;
ITEM p1[1024], p2[1024];
int np1, np2;

int main()
{
	int i, j;
	LIST_NODE *p, *q;
	int t;
	ITEM ti;
	
	head = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	tail = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	np1 = np2 = 0;
	do
	{
		scanf("%d %d", &p1[np1].a, &p1[np1].n);
		np1++;
	} while (getchar() != '\n');
	while (scanf("%d %d", &p2[np2].a, &p2[np2].n) != EOF)
	{
		np2++;
	}
	//for (i = 0; i < np1; i++) printf("%d %d ", p1[i].a, p1[i].n);
	//printf("\n");
	//for (j = 0; j < np2; j++) printf("%d %d ", p2[j].a, p2[j].n);
	//printf("\n");
	for (i = 0; i < np1; i++)
	{
		for (j = 0; j < np2; j++)
		{
			t = p1[i].n + p2[j].n;
			p = head->next;
			while (p != tail)
			{
				if (p->v.n == t)
				{
					p->v.a += p1[i].a * p2[j].a;
					break;
				}
				else p = p->next;
			}
			if (p == tail)
			{
				p = head->next;
				while (p != tail)
				{
					if (p->v.n < t) break;
					else p = p->next;
				}
				ti.n = t;
				ti.a = p1[i].a * p2[j].a;
				q = LIST_NEW(LIST_NODE, ti);
				LIST_INSERT(LIST_NODE, p->prev, q);
			}
		}
	}
	p = head->next;
	while (p != tail)
	{
		if (p->v.a != 0)
		{
			printf("%d %d ", p->v.a, p->v.n);
		}
		p = p->next;
	}
	return 0;
}
BUILD_LIST_FUNS(ITEM, LIST_NODE)



