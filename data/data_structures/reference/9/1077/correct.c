#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
};

void linecmp(struct line array[],int n)
{
	struct line tmp;
	int i,j;
	for(i=0;i<n;i++)
	for(j=i;j<n;j++)
	{
		if(array[i].x1>array[j].x1)
		{
			tmp=array[i];
			array[i]=array[j];
			array[j]=tmp;
		}
	}
}
#define MAXLINE 1024
int main()
{
	struct line infor[105];
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&infor[i].x1,&infor[i].y1,&infor[i].x2,&infor[i].y2);
	}
	linecmp(infor,n);
	int count_max=1;
	int x1_max=0,y1_max=0;
	for(i=0;i<n;i++)
	{
		int x2,y2,count=1;
		x2=infor[i].x2;
		y2=infor[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(x2==infor[j].x1&&y2==infor[j].y1)
			{
				count++;
				x2=infor[j].x2;
				y2=infor[j].y2;
			}
		}
		if(count>count_max)
		{
			count_max=count;
			x1_max=infor[i].x1;
			y1_max=infor[i].y1;
		}
	}
	printf("%d %d %d",count_max,x1_max,y1_max);
	return 0;
}

