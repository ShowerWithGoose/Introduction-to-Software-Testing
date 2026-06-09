#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
	struct line
	{
		int x1;
		int y1;
		int x2;
		int y2;
		int last;
		int next;
		int used;
	};
	struct all//长线段首坐标及长度 
	{
		int firstx;
		int firsty;
		int length;
	};
	struct all b[1000];
	struct line a[110];
	int i=0,j,k=-1,n,max=0;
	scanf ("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf ("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].next=-1;
		a[i].last=-1;
		a[i].used=0;//遍历数组连接线段时判断该线段所在长线段是否已被记录 
		for (j=0;j<i;j++)//连接线段 
		{
			if (a[j].x2==a[i].x1&&a[j].y2==a[i].y1)
			{
				a[j].next=i;
				a[i].last=j;
	 		}
			if (a[j].x1==a[i].x2&&a[j].y1==a[i].y2)
			{
				a[j].last=i;
				a[i].next=j;
			}
		}
	}
	
		for (i=0;i<n;i++)
		{
			while (a[i].used==1||(a[i].next+a[i].last)==-2)//跳过使用过的线段和单条线段 
			{
				i++;
			 }
			 k++;//开始录入长线段数组 
			 b[k].length=1; 
			 b[k].firstx=a[i].x1;
			 b[k].firsty=a[i].y1;
			 if (a[i].next!=-1)
			 {
			 	for (j=i;a[j].next!=-1;)//向后连接 
			 	{
			 		b[k].length++;
			 		j=a[j].next;
				 }
				 for (j=i;a[j].last!=-1;)
				 {
				 	b[k].length++;
				 	j=a[j].last;
				 	b[k].firstx=a[j].x1;
				 	b[k].firsty=a[j].y1;
				 }
				 a[i].used=1;//该线段已被判断 
			 }
		}
		for (i=0;i<=k;i++)
		{
			if (b[i].length>b[max].length)
			{
				max=i;
			}
		}
		printf("%d %d %d",b[max].length,b[max].firstx,b[max].firsty);
	
	return 0;
}

