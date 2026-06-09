#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int num;
	int index;
	struct node *link;
};
typedef struct node Nodeptr;
Nodeptr a, b, c;
int i, j = 0;
Nodeptr produce_list(void)
{
	Nodeptr *list = NULL, *p = NULL, *t = NULL;
	for (i = 0; i < 300; i++)
	{
		t = (Nodeptr *)malloc(sizeof(Nodeptr));
		scanf("%d%d", &t->num, &t->index);
		if (getchar() == '\n')
		{
			if (i == 0)
			{
				list = p = t;
				p->link = NULL;
				break;
			}
			p->link = t;
			p = p->link;
			p->link = NULL;
			break;
		}
		if (list == NULL)
		{
			list = p = t;
			continue;
		}
		else
		{
			p->link = t;
			p = p->link;
		}
	}
	return *list;
}
void sort(Nodeptr *head)
{
	Nodeptr *r, *tail;
	r = head;
	tail = NULL;
	if (r == NULL || r->link == NULL)
	{
		return;
	}
	while (r != tail)
	{
		while (r->link != tail)
		{
			if (r->index < r->link->index)
			{
				int temp = r->index;
				r->index = r->link->index;
				r->link->index = temp;
				int temp1 = r->num;
				r->num = r->link->num;
				r->link->num = temp1;
			}
			r = r->link;
		}
		tail = r;
		r = head;
	}
}

void multiply(Nodeptr *a, Nodeptr *b)
{
	Nodeptr *list = NULL, *p = NULL, *p1 = NULL, *p2 = NULL, *t = NULL;
	int count = 0;
	for (p1 = a; p1 != NULL; p1 = p1->link)
	{
		for (p2 = b; p2 != NULL; p2 = p2->link)
		{
			t = (Nodeptr *)malloc(sizeof(Nodeptr));
			t->num = p1->num * p2->num;
			t->index = p1->index + p2->index;
			if (list == NULL)
			{
				list = p = t;
				count++;
			}
			else
			{
				p->link = t;
				p = p->link;
				count++;
			}
		}
	}
	p->link = NULL;
	for (p = list; p != NULL; p = p->link)
	{
		Nodeptr *a1 = p, *a2 = NULL;
		for (a2 = p->link; a2 != NULL; a2 = a2->link)
		{
			if (a2->index == p->index)
			{
				p->num += a2->num;
				a1->link = a2->link;
				free(a2);
				a2 = a1->link;
			}
			a1 = a2;
		}
	}
	sort(list);
	for (p = list; p != NULL; p = p->link)
		printf("%d %d ", p->num, p->index);
}
int main()
{
	a = produce_list();
	b = produce_list();
	multiply(&a, &b);
	return 0;
}

