#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>

struct formula 
{
	int coe;
	int pow;
	struct formula* link;
};

int main()
{
	int a, n, aa, nn;
	char c;
	char d;
	struct formula* p, * q, * r, * m, * s, * o;
	struct formula* lista = NULL;
	struct formula* listb = NULL;
	struct formula* listc = (struct formula*)malloc(sizeof(struct formula));
	listc->coe = 0;
	listc->pow = 0;
	listc->link = NULL;
	do {
		scanf("%d%d%c", &a, &n, &c);
		q = (struct formula*)malloc(sizeof(struct formula));
		q->coe = a;
		q->pow = n;
		q->link = NULL;
		if (lista == NULL) {
			lista = p = q;
		}
		else {
			p->link = q;
			p = p->link;

		}
	} while (c != '\n');
	do {
		scanf("%d%d%c", &aa, &nn, &d);
		
		for (p = lista;p != NULL;p = p->link)
		{
			r = (struct formula*)malloc(sizeof(struct formula));
			r->coe = aa*(p->coe);
			r->pow = nn+(p->pow);
			r->link = NULL;
			if (listb == NULL)
			{
				listb = m = r;
			}
			else 
			{
				m->link = r;
				m = m->link;
			}
		}
	} while (d != '\n');

	for (s = listb;s!= NULL;s=o)
	{
		o = s->link;
		for (p = listc;p != NULL;q = p, p = p->link)
		{
			if (s->pow > p->pow) {
				if (p == listc)
				{
					s->link = listc;
					listc = s;
					break;
				}
				else
				{
					s->link = p;
					q->link = s;
					break;
				}
			}
			else if (s->pow == p->pow)
			{
				p->coe += s->coe;
				break;

			}
		}
		if (p == NULL) 
		{ q->link = s;
		s->link = NULL;
		}
	}
	for (p = listc;p != NULL;p = p->link)
	{if(p->coe!=0)
		printf("%d %d ", p->coe, p->pow);

	}

	return 0;
}



