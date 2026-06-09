#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int comp(const void* a, const void* b)
{
	return ((int*)b)[1] - ((int*)a)[1];
}
int main()
{
	int a[102][2] = { 0 }, b[102][2] = { 0 };
	int c[800][2] = { 0 }, an, bn, i , j, k;
	char pdf;
	i = 0;
	do
	{
		scanf("%d %d%c", &a[i][0], &a[i][1], &pdf);
		i++;
	} while (pdf != '\n');
	an = i;
	i = 0;
	do
	{
		scanf("%d %d%c", &b[i][0], &b[i][1], &pdf);
		i++;
	} while (pdf != '\n');
	bn = i;
	i = 0;
	k = 0;
	for (i = 0; i < an; i++)
	{
		for (j = 0; j < bn; j++)
		{
			c[k][0] = a[i][0] * b[j][0];
			c[k][1] = a[i][1] + b[j][1];
			k++;
		}
	}
	qsort(c, k, 2 * sizeof(int), comp);
	for (i = 0; i < k; i++)
	{
		if (c[i][1] == c[i + 1][1])
		{
			c[i][0] += c[i + 1][0];
			c[i + 1][0] = 0;
			c[i + 1][1] = 0;
		}
	}
	qsort(c, k, 2 * sizeof(int), comp);
	for (i = 0; i < k; i++)
	{
		if (c[i][1] == c[i + 1][1])
		{
			c[i][0] += c[i + 1][0];
			c[i + 1][0] = 0;
			c[i + 1][1] = 0;
		}
	}
	qsort(c, k, 2 * sizeof(int), comp);
	for (i = 0; i < k; i++)
	{
		if (c[i][0] != 0)
		{
			printf("%d %d ", c[i][0], c[i][1]);
		}
	}
	return 0;
}


