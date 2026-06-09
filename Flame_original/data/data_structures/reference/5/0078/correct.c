#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct element
{
	int coe;
	int pow;
	struct element *link;
};

typedef struct element formula;
formula a, b, c;
int i, j = 0;

formula produce_list(void)
{
	formula *list = NULL, *p = NULL, *t = NULL;
	for (i = 0; i < 300; i++)
	{
		t = (formula *)malloc(sizeof(formula));
		scanf("%d%d", &t->coe, &t->pow);
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

void sort(formula *head)       //
{
	formula *r, *tail;
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
			if (r->pow < r->link->pow)
			{
				int temp = r->pow;
				r->pow = r->link->pow;
				r->link->pow = temp;
				int temp1 = r->coe;
				r->coe = r->link->coe;
				r->link->coe = temp1;
			}
			r = r->link;
		}
		tail = r;
		r = head;
	}
}

void multiply(formula *a, formula *b)
{
	formula *list = NULL, *p = NULL, *p1 = NULL, *p2 = NULL, *t = NULL;
	int count = 0;
	for (p1 = a; p1 != NULL; p1 = p1->link)
	{
		for (p2 = b; p2 != NULL; p2 = p2->link)
		{
			t = (formula *)malloc(sizeof(formula));
			t->coe = p1->coe * p2->coe;
			t->pow = p1->pow + p2->pow;
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
		formula *r1 = p, *r2 = NULL;
		for (r2 = p->link; r2 != NULL; r2 = r2->link)
		{
			if (r2->pow == p->pow)
			{
				p->coe += r2->coe;
				r1->link = r2->link;
				free(r2);
				r2 = r1->link;
			}
			r1 = r2;
		}
	}
	sort(list);
	for (p = list; p != NULL; p = p->link)
		printf("%d %d ", p->coe, p->pow);
}

int main()
{
	a = produce_list();
	b = produce_list();
	multiply(&a, &b);
	return 0;
}

