#include<stdio.h>
#include<string.h>
#include<math.h>

struct dian{
	int x1;
	int y1;
	int x2;
	int y2;
};

int main(void)
{
	struct dian xian[205];
	struct dian swap;
	int n,i,j;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	scanf("%d %d %d %d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(xian[i].x1 > xian[j].x1)
			{
				swap = xian[i];
				xian[i] = xian[j];
				xian[j] = swap;
			}
		}
	}
	int cnt = 1,mcnt = 1;
	int x2,y2,mx1,my1;
	for(i = 0; i < n; i++)
	{
		x2 = xian[i].x2;
		y2 = xian[i].y2;
		for(j = i + 1;j < n; j++)
		{
			if(xian[j].x1 == x2 && xian[j].y1 == y2)
			{
				x2 = xian[j].x2;
				y2 = xian[j].y2;
				cnt++;
			}
		}
		if(cnt > mcnt)
		{
			mx1 = xian[i].x1;
			my1 = xian[i].y1;
			mcnt = cnt;
		}
		cnt = 1;
	}
	printf("%d %d %d\n",mcnt,mx1,my1);
	return 0;
} 

