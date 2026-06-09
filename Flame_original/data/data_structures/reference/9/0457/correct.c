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
	int x;
	int y;
}POINT;
typedef struct
{
	POINT s;
	POINT t;
}LINE;
typedef struct
{
	POINT s;
	POINT t;
	int num;
}CUR_LINE;
BUILD_LIST_NODE_STRUCTURE(CUR_LINE, LIST_NODE)

BUILD_LIST_FUN_DEFS(CUR_LINE, LIST_NODE)
int cmp(const void *a, const void *b);

LIST_NODE *head, *tail;
LINE lines[1024];
int nlines;

int main()
{
	int i;
	LIST_NODE *p, *q;
	CUR_LINE t;
	int max_lines;
	POINT ans;
	
	head = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	tail = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	scanf("%d", &nlines);
	for (i = 0; i < nlines; i++) scanf("%d %d %d %d", &lines[i].s.x, &lines[i].s.y, &lines[i].t.x, &lines[i].t.y);
	qsort(lines, nlines, sizeof(LINE), cmp);
	for (i = 0; i < nlines; i++)
	{
		p = head->next;
		while (p != tail)
		{
			if (p->v.t.x == lines[i].s.x && p->v.t.y == lines[i].s.y)
			{
				p->v.num++;
				p->v.t.x = lines[i].t.x;
				p->v.t.y = lines[i].t.y;
				break;
			}
			else p = p->next;
		}
		if (p == tail)
		{
			t.s = lines[i].s;
			t.t = lines[i].t;
			t.num = 1;
			q = LIST_NEW(LIST_NODE, t);
			LIST_INSERT(LIST_NODE, tail->prev, q);
		}
	}
	max_lines = 0;
	p = head->next;
	while (p != tail)
	{
		if (p->v.num > max_lines)
		{
			max_lines = p->v.num;
			ans = p->v.s;
		}
		p = p->next;
	}
	printf("%d %d %d", max_lines, ans.x, ans.y);
	return 0;
}
BUILD_LIST_FUNS(CUR_LINE, LIST_NODE)
int cmp(const void *a, const void *b)
{
	LINE *la = (LINE *)a, *lb = (LINE *)b;
	if (la->t.x < lb->t.x || (la->t.x == lb->t.x && la->t.y < lb->t.y)) return -1;
	else if (la->t.x == lb->t.x && la->t.y == lb->t.y) return 0;
	else return 1;
}

