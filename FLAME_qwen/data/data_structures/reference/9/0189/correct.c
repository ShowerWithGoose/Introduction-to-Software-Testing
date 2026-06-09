#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct zb {
	int x1, y1;
	int x2, y2;
};
struct zb zuobiao[120];
int cmp(const void* p1, const void* p2)
{
	struct zb c = *(struct zb*)p1;
	struct zb d = *(struct zb*)p2;
	if (c.x1 != d.x1) return c.x1 - d.x1;
	else   return c.y1 - d.y1;
}
int main()
{
	int n;
	scanf("%d", &n);
	int i = 0, j = 0, l = 0, hold = 0, hold1 = 0, hold2 = 0,flag,m;
	int count[120] ;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &zuobiao[i].x1, &zuobiao[i].y1, &zuobiao[i].x2, &zuobiao[i].y2);
	}
	qsort(zuobiao, n+1, sizeof(zuobiao[0]), cmp);
	for (i = 1; i <= n - 1; i++)
	{
		m = i;
		l = i;
		count[m] = 1;
		for (j = i + 1; j <= n; j++)
		{    
			if ((zuobiao[j].x1 == zuobiao[l].x2) && (zuobiao[j].y1 == zuobiao[l].y2))
			{
				flag = 1;
				count[m]++;
				for (l = j + 1; l <= n; l++)
				{
					if ((zuobiao[j].x2 == zuobiao[l].x1) && (zuobiao[j].y2 == zuobiao[l].y1) && (l != j))
					{
						j = l;
						i = l;
						count[m]++;
						flag = 1;
						break;
					}
					else  continue;
				}
			}
			else continue;
		}
		i = m;
	}
		for (i = 1; i <= n - 1; i++)
		{
			for (j = 1; j <= n - 1 - i; j++)
			{
				if (count[j] > count[j + 1])
				{
					hold = count[j];
					count[j] = count[j + 1];
					count[j + 1] = hold;
					hold1 = zuobiao[j].x1;
					zuobiao[j].x1 = zuobiao[j + 1].x1;
					zuobiao[j + 1].x1 = hold1;
					hold2 = zuobiao[j].y1;
					zuobiao[j].y1 = zuobiao[j + 1].y1;
					zuobiao[j + 1].y1 = hold2;
				}
			}
		}
		printf("%d %d %d", count[n - 1], zuobiao[n - 1].x1, zuobiao[n - 1].y1);
		return  0;
}
