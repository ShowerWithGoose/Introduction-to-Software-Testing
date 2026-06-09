#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list_multi
{
	int a;
	int b;
	struct list_multi *next;
};
struct list_multi *start;
struct list_multi *ans_start;
struct list_multi *have_same_power(int n);
int main()
{
	char cond = 0;
	int m, n, one, two;
	start = NULL;
	struct list_multi *p, *q, *if_same = NULL;
	do
	{
		scanf("%d%d%c", &m, &n, &cond);
		p = (struct list_multi *)malloc(sizeof(struct list_multi));
		p->a = m;
		p->b = n;
		if (start == NULL)
			start = q = p;
		else
		{
			q->next = p;
			q = p;
		}
	} while (cond != '\n');
	p->next = NULL;

	ans_start = (struct list_multi *)malloc(sizeof(struct list_multi));
	ans_start->b = -1;
	ans_start->next = NULL;

	do
	{
		scanf("%d%d%c", &m, &n, &cond);
		q = start;
		do
		{
			one = m * q->a;
			two = n + q->b;
			q = q->next;
			//printf("one:%d  two:%d\n", one, two);
			if_same = have_same_power(two);
			if (if_same->b == two)
				if_same->a += one;
			else
			{
				p = (struct list_multi *)malloc(sizeof(struct list_multi));
				p->a = one;
				p->b = two;
				p->next = if_same->next;
				if_same->next = p;
			}
		} while (q != NULL);
	} while (cond != '\n');

	q = ans_start->next;
	do
	{
		printf("%d %d ", q->a, q->b);
		q = q->next;
	} while (q != NULL);

	return 0;
}

struct list_multi *have_same_power(int n)
{
	struct list_multi *temp = ans_start;
	while (1)
	{
		if (temp->b == n)
			return temp;
		if (temp->next == NULL)
			return temp;
		if (temp->next->b < n)
			return temp;

		temp = temp->next;
	}
}
