#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct link{
	int x1;
	int y1;
	int x2;
	int y2;
}point[105],tmp;
int main()
{
	int n,i,j,max=0,num,k,put_x,put_y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(point[i].x1>point[j].x1)
			{
				tmp=point[i];
				point[i]=point[j];
				point[j]=tmp;
			}
		}
	for(i=0;i<n;i++)
	{
		num=1;
		k=i;
		for(j=k+1;j<n;j++)
		{
			if(point[k].x2==point[j].x1&&point[k].y2==point[j].y1)
			{
				num++;
				k=j;
			}
		}
		if(num>max)
		{
			max=num;
			put_x=point[i].x1;
			put_y=point[i].y1;
		}
	}
	printf("%d %d %d",max,put_x,put_y);
	return 0;
}


