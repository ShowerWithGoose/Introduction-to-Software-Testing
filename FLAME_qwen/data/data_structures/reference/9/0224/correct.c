#include<stdio.h>
#include<stdlib.h>
struct location{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{
	int n,i,j;
	struct location loc[200];
	struct location tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&loc[i].x1,&loc[i].y1,&loc[i].x2,&loc[i].y2);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(loc[i].x1>loc[j].x1)
			{
				tmp=loc[i];
				loc[i]=loc[j];
				loc[j]=tmp;
			}
		}
	}
	int max=1,x1_max=0,y1_max=0;
	for(i=0;i<n;i++)
	{
		int x2,y2,len=1;
		x2=loc[i].x2;
		y2=loc[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(x2==loc[j].x1&&y2==loc[j].y1)
			{
				len++;
				x2=loc[j].x2;
				y2=loc[j].y2;
			}
		}
		if(len>max)
		{
			max=len;
			x1_max=loc[i].x1;
			y1_max=loc[i].y1;
		}
	}
	printf("%d %d %d\n",max,x1_max,y1_max);
    return 0;
}

