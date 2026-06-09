#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct item
{
	int fac;
	int pow;
};

struct item a[1000];
struct item b[1000];
struct item c[1000];

int cmp(const void* a, const void* b);

int main()
{
	int n1 = 0;
	char ch = 0;
	do
	{
		scanf("%d%d%c", &a[n1].fac, &a[n1].pow, &ch);
		n1++;
	} while (ch != '\n');

	ch = 0;
	int n2 = 0;
	do
	{
		scanf("%d%d%c", &b[n2].fac, &b[n2].pow, &ch);
		n2++;
	} while (ch != '\n');

	int n3 = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			c[n3].fac = a[i].fac * b[j].fac;
			c[n3].pow = a[i].pow + b[j].pow;
			n3++;
		}
	}

	for (int i = 0; i < n3 - 1; i++)
	{
		for (int j = 0; j < n3; j++)
		{
			if (c[i].pow == c[j].pow && j != i)
			{
				c[i].fac += c[j].fac;
				c[j].fac = c[n3-1].fac;
				c[j].pow = c[n3-1].pow;
				n3--;
			}
		}
	}

	qsort(c, n3, sizeof(struct item), cmp);

	for (int i = 0; i < n3; i++)
	{
		printf("%d %d ", c[i].fac, c[i].pow);
	}

	return 0;
}


int cmp(const void* a, const void* b)
{
	struct item* p1 = (struct item*)a;
	struct item* p2 = (struct item*)b;
	return p2->pow - p1->pow;
}
