#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct line
{
	int x1;
	int x2;
	int y1;
	int y2;
	int flag;
};

int main()
{
	struct line a[110];
	int n, i, j, max = 0, k, m;
	int num[110]= {0};
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);

	for(i = 1; i <= n; i++)
		a[i].flag = 0;

	for(i = 1; i <= n; i++)
	{
		if(a[i].flag == 1) continue;
		else
		{
			num[i] = 1;
			for(m = 1; m <= 5; m++)
			{
				for(j = i + 1; j <= n; j++)
				{
					if(a[j].flag == 1) continue;
					if(a[j].x1 == a[i].x2 && a[j].y1 == a[i].y2)
					{
						num[i]++;
						a[j].flag = 1;
						a[i].x2 = a[j].x2;
						a[i].y2 = a[j].y2;
					}
					else if(a[j].x2 == a[i].x1 && a[j].y2 == a[i].y1)
					{
						num[i]++;
						a[j].flag = 1;
						a[i].x1 = a[j].x1;
						a[i].y1 = a[j].y1;
					}
				}
			}

		}
	}

	for(i = 1; i <= n; i++)
	{
		if(num[i] > max) max = num[i];
	}
	for(i = 1; i <= n; i++)
	{
		if(num[i] == max) k = i;
	}

	printf("%d %d %d",max,a[k].x1,a[k].y1);

	return 0;
}


