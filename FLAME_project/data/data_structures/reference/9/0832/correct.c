#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
}line;
line t[101];
int cmp(const void*a,const void*b)
{
	line* p = (line*)a;
	line* q = (line*)b;
	if ((p->x1) > (q->x1))
		return 1;
	if ((p->x1) < (q->x1))
		return -1;
	if ((p->x1) == (q->x1))
	{
		if ((p->y1) > (q->y1))
			return 1;
		if ((p->y1) < (q->y1))
			return -1;
	}
}
int main()
{
	int i, j, k, n, max = 0, flag = 0, cnt = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &t[i].x1, &t[i].y1, &t[i].x2, &t[i].y2);
	}
	qsort(t, n, sizeof(line), cmp);
	/*for (i = 0; i < n; i++)
	{
		printf("%d %d %d %d\n", t[i].x1, t[i].y1, t[i].x2, t[i].y2);
	}*/
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (t[j].x1 >= t[k].x2)
			{
				if (t[k].x2 == t[j].x1 && t[k].y2 == t[j].y1)
				{
					cnt++;
					k = j;
				}
			}
			else
				continue;
		}
		if (cnt > max)
		{
			max = cnt;
			flag = i;
		}
		cnt = 1;
	}
	printf("%d %d %d", max, t[flag].x1, t[flag].y1);
	return 0;
}
