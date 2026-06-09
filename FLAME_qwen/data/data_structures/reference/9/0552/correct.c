#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct line/*建立线段结构体，包含起始坐标和终点坐标*/
{
	int startx;
	int starty;
	int endx;
	int endy;
}LINE;
int cmp(const void *p1,const void *p2)/*将所有线段按照起始横坐标排序从小到大排序，若相同则起始纵坐标小的在前*/
{
	LINE *q1=(LINE *)p1;
	LINE *q2=(LINE *)p2;
	if(q1->startx!=q2->startx) return q1->startx-q2->startx;
	else return q1->starty-q2->starty; 
}
int main()
{
	LINE a[105];
	int n,i,j,start1,start2,end1,end2,num,max=0;
	int startfinalx,startfinaly;/*用来存储最长的连续线段的起点坐标*/
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i].startx,&a[i].starty,&a[i].endx,&a[i].endy);
	qsort(a,n,sizeof(LINE),cmp);
	for(i=0;i<n;i++)
	{
		num=1;
		start1=a[i].startx;start2=a[i].starty;
		end1=a[i].endx;end2=a[i].endy;
		for(j=i+1;j<n;j++)
		{
			if((a[j].startx==end1)&&(a[j].starty==end2))
			{
				num++;
				end1=a[j].endx;end2=a[j].endy;
			}
		}
		if(num>max)
		{
			max=num;
			startfinalx=start1;startfinaly=start2;	
		} 
	}
	printf("%d %d %d",max,startfinalx,startfinaly);
	return 0 ;	
} 	

