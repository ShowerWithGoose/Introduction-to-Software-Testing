#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct nodes
{
	int n_a;
	int n_b;
	struct nodes* link;
}node;
node* head1 = NULL, * head2 = NULL, * r1 = NULL, * r2 = NULL, * p1 = NULL, * p2 = NULL;
node* head0 = NULL, * r0 = NULL, * p0 = NULL, * p = NULL;
FILE* OUT1, * OUT2, * IN1, * IN2;
char s[200];
int main()
{
	gets(s);
	OUT1 = fopen("out1.txt", "w");
	fprintf(OUT1, "%s", s);
	OUT2 = fopen("out2.txt", "w");
	gets(s);
	fprintf(OUT2, "%s", s);
	fclose(OUT1);
	fclose(OUT2);
	IN1 = fopen("out1.txt", "r");
	IN2 = fopen("out2.txt", "r");
	while (1)
	{
		if (head1 == NULL)
		{
			p1 = (node*)malloc(sizeof(node));
			fscanf(IN1,"%d%d", &p1->n_a, &p1->n_b);
			head1 = p1;
			r1 = p1;
		}
		else
		{
			p1 = (node*)malloc(sizeof(node));
			if (fscanf(IN1, "%d%d", &p1->n_a, &p1->n_b) != EOF)
			{
				r1->link = p1;
				r1 = p1;
			}
			else
			{
				break;
			}
		}
	}
	r1->link = NULL;

	while (1)
	{
		if (head2 == NULL)
		{
			p2 = (node*)malloc(sizeof(node));
			fscanf(IN2, "%d%d", &p2->n_a, &p2->n_b);
			head2 = p2;
			r2 = p2;
		}
		else
		{
			p2 = (node*)malloc(sizeof(node));
			if (fscanf(IN2, "%d%d", &p2->n_a, &p2->n_b) != EOF)
			{
				r2->link = p2;
				r2 = p2;
			}
			else
			{
				break;
			}
		}
	}
	r2->link = NULL;
	p1 = head1;
	p2 = head2;

	fclose(IN1);
	fclose(IN2);

	while (p1 != NULL)
	{
		while (p2 != NULL)
		{
			p0= (node*)malloc(sizeof(node));
			p0->n_a = p1->n_a * p2->n_a;
			p0->n_b = p1->n_b + p2->n_b;
			p0->link = NULL;
			if (head0 == NULL)
			{
				head0 = p0;
			}
			else
			{
				p = head0;
				int point = 0;
				while (p != NULL)
				{
					if (p->n_b == p0->n_b)
					{
						p->n_a = p->n_a + p0->n_a;
						point = 1;
						break;
					}
					p = p->link;
				}

				if (point == 0)
				{
					p = head0;
					while (p != NULL)
					{
						if (p->link != NULL)
						{
							if (p->link->n_b > p0->n_b)
							{
								p = p->link;
							}
							else
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
					p0->link = p->link;
					p->link = p0;
				}
			}
			p2 = p2->link;
		}
		p1 = p1->link;
		p2 = head2;
	}
	p0 = head0;
	while (p0 != NULL)
	{
		printf("%d %d ", p0->n_a, p0->n_b);
		p0 = p0->link;
	}
	return 0;
}


