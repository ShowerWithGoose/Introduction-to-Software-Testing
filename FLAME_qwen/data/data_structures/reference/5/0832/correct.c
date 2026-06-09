#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
struct mul {
	int coe;
	int pow;
};
struct mul l1[300], l2[300], final[600];
int cmp(const void* a, const void* b)
{
	struct mul* p = (struct mul*)a;
	struct mul* q = (struct mul*)b;
	return (q->pow) - (p->pow);
}
int main()
{
	int i = 0, j = 0, k, m, n, s;
	char c;
	do {
		scanf("%d%d%c", &l1[i].coe, &l1[i].pow, &c);
		i++;
	} while (c != '\n');
	m = i;
	do {
		scanf("%d%d%c", &l2[j].coe, &l2[j].pow, &c);
		j++;
	} while (c != '\n');
	n = j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			final[i * n + j].coe = l1[i].coe * l2[j].coe;
			final[i * n + j].pow = l1[i].pow + l2[j].pow;
		}
	}
	s = m * n;
	for (i = 0; i < s; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (final[i].pow == final[j].pow)
			{
				final[j].coe += final[i].coe;
				for (k = i; k < s; k++)
				{
					final[k].pow = final[k + 1].pow;
					final[k].coe = final[k + 1].coe;
				}
				s--; k--;
			}
		}
	}
	qsort(final, s, sizeof(struct mul), cmp);
	for (i = 0; i < s; i++)
	{
		printf("%d %d ", final[i].coe, final[i].pow);
	}
	return 0;
}
