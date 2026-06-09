#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct zb{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}zuob[105], temp;
int main()
{
	int n, i, j, m, max=-1;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d", &zuob[i].x1, &zuob[i].y1, &zuob[i].x2, &zuob[i].y2);
		zuob[i].num=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(zuob[j].x1<zuob[i].x1)
			{
				temp = zuob[i];
				zuob[i] = zuob[j];
				zuob[j] = temp;
			}
			else if(zuob[j].x1 == zuob[i].x1)
			{
				if(zuob[j].y1<zuob[i].y1)
				{
					temp = zuob[i];
					zuob[i] = zuob[j];
					zuob[j] = temp;
				 } 
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			else if(zuob[i].x2==zuob[j].x1 && zuob[i].y2==zuob[j].y1)
			{
				zuob[i].x2=zuob[j].x2;
				zuob[i].y2=zuob[j].y2;
				zuob[i].num+=zuob[j].num; 
				zuob[j].x1=0, zuob[j].y1=0, zuob[j].x2=0, zuob[j].y2=0, zuob[j].num=0;
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(zuob[i].num>max)
		{
			max=zuob[i].num;
			m=i;
		}
	}
		printf("%d %d %d",max, zuob[m].x1, zuob[m].y1);
	return 0;
}

