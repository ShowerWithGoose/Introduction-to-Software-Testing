#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct polynomial
{
	int coe;	//coefficient
	int exp;	//exponent
}a[1000], b[1000], c[2000], d[2000];

int cmp(const void* a, const void* b)
{
	struct polynomial* aa = (struct polynomial*)a;
	struct polynomial* bb = (struct polynomial*)b;
	return (((bb->exp) > (aa->exp)) ? 1 : -1);
}

int main()
{
	int temp1, temp2, i = 1, j = 1;	//π§æﬂ»À
	scanf("%d%d", &temp1, &temp2);
	a[0].coe = temp1;
	a[0].exp = temp2;
	char ch;
	ch = getchar();
	while (temp2 != 0 && ch != '\n')
	{
		scanf("%d%d", &temp1, &temp2);
		a[i].coe = temp1;
		a[i].exp = temp2;
		i++;
		ch = getchar();
	}
	scanf("%d%d", &temp1, &temp2);
	b[0].coe = temp1;
	b[0].exp = temp2;
	ch = getchar();
	while (temp2 != 0 && ch != '\n')
	{
		scanf("%d%d", &temp1, &temp2);
		b[j].coe = temp1;
		b[j].exp = temp2;
		j++;
		ch = getchar();
	}
	for (int m = 0; m < j; m++)
	{
		for (int n = 0; n < i; n++)
		{
			c[m * i + n].coe = b[m].coe * a[n].coe;
			c[m * i + n].exp = b[m].exp + a[n].exp;
		}
	}
	qsort(c, i * j, sizeof(c[0]), cmp);
	int k = 0, t = 0;
	while (k < i * j)
	{
		d[t].exp = c[k].exp;
		d[t].coe = 0;
		while (c[k].exp == d[t].exp && k < i * j)
		{
			d[t].coe += c[k].coe;
			k++;
		}
		t++;
	}
	for (int s = 0; s < t - 1; s++)
	{
		if(d[s].coe != 0)
			printf("%d %d ", d[s].coe, d[s].exp);
	}
	if (d[t - 1].coe != 0)
		printf("%d %d", d[t - 1].coe, d[t - 1].exp);
	return 0;
}
