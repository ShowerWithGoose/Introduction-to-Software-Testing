#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct line
{
	int x1;
	int y1;
	int x2;
	int y2;	
};

int cmp(const void* a1, const void* a2)
{
	return ((struct line *)a1) -> x1 - ((struct line *)a2) -> x1;
}

int main()
{
	int num, i, j;
	int len_max = 0, x1_max = 0, y1_max = 0;
	int cnt;
	
	scanf("%d", &num);
	struct line a[200];
	
	for(i = 0;i < num; i++)
	{
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	}
	
 	qsort(a, num, sizeof(a[0]), cmp);
	
	for(i = 0;i < num; i++)
	{
		int xtemp, ytemp;
		xtemp = a[i].x2;
		ytemp = a[i].y2;
		
		cnt = 1;
		
		for(j = i + 1; j < num; j++)
		{
			if(a[i].x2 == a[j].x1 && a[i].y2 == a[j].y2)
			{
				cnt++;
				xtemp = a[j].x2;
				ytemp = a[j].y2;
			}
		}
		
		if(cnt > len_max)
		{
			len_max = cnt;
			x1_max = a[i].x1;
			y1_max = a[i].y1;
		}
	}
	
	printf("%d %d %d\n", len_max, x1_max, y1_max);
	
	return 0;
}
