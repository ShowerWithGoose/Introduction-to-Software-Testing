#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct line{
	int x1;
	int x2;
	int y1;
	int y2;
	int numline;
};//结构体 
typedef struct line L;
L L1[105];
L L2;
int main()
{
	int n,i,j;
	int nummax;
	nummax=0;
	int max;
	max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) L1[i].numline=1;  //初始化，线段的长度都为1 
	for(i=0;i<n;i++)
	{
			scanf("%d %d %d %d",&L1[i].x1,&L1[i].y1,&L1[i].x2,&L1[i].y2);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(L1[i].x1>L1[j].x1)
			{
				L2=L1[j];
				L1[j]=L1[i];
				L1[i]=L2;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				continue; //同一点，跳过 
			}
			else
			{
				if(L1[j].x1 == L1[i].x2 && L1[j].y1 == L1[i].y2) //如果可以相连 
				{
					L1[i].x2 = L1[j].x2;		//合并 
					L1[i].y2 = L1[j].y2;     //合并 
					L1[i].numline += L1[j].numline;  //线段条数增加 
					L1[j].x1=0,L1[j].y1=0,L1[j].x2=0,L1[j].y2=0,L1[j].numline=0;//合并的线段清零 
				}
			}
			
		}
	}
	for(i=0;i<n;i++)
	{
		if(L1[i].numline>nummax)
		{
			nummax=L1[i].numline;
			max=i;
		}
	}
	printf("%d %d %d",nummax,L1[max].x1,L1[max].y1);
	return 0;
}

