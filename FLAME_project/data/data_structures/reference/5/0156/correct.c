#include <stdio.h>
#include <malloc.h>

struct element
{
	int bef_variable;
	int index_variable;
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
		scanf("%d%d", &t->bef_variable, &t->index_variable);
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

void sort(formula *head)
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
			if (r->index_variable < r->link->index_variable)
			{
				int temp = r->index_variable;
				r->index_variable = r->link->index_variable;
				r->link->index_variable = temp;
				int temp1 = r->bef_variable;
				r->bef_variable = r->link->bef_variable;
				r->link->bef_variable = temp1;
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
			t->bef_variable = p1->bef_variable * p2->bef_variable;
			t->index_variable = p1->index_variable + p2->index_variable;
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
			if (r2->index_variable == p->index_variable)
			{
				p->bef_variable += r2->bef_variable;
				r1->link = r2->link;
				free(r2);
				r2 = r1->link;
			}
			r1 = r2;
		}
	}
	sort(list);
	for (p = list; p != NULL; p = p->link)
		printf("%d %d ", p->bef_variable, p->index_variable);
}

int main()
{
	a = produce_list();
	b = produce_list();
	multiply(&a, &b);
	return 0;
}



