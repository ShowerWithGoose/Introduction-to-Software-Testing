#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct dot{
	int x1;
	int x2;
	int y1;
	int y2;
	int len;
}lin[105];
int cmp(const void *x,const void *y)
{
	struct dot *a=(struct dot *)x;
	struct dot *b=(struct dot *)y;
return b->len-a->len;
}//按线段长度排，最长的是第一个 
int cmp2(const void *x,const void *y)
{
	struct dot *a=(struct dot *)x;
	struct dot *b=(struct dot *)y;
	if(a->x1!=b->x1) 
return a->x1-b->x1;
    else
return a->y1-b->y1;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("\n%d %d %d %d",&lin[i].x1,&lin[i].y1,&lin[i].x2,&lin[i].y2);
		lin[i].len=1;
	}
	qsort(lin,n,sizeof(struct dot),cmp2);//此时lin中线段是从左到右（从下到上排序） 
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(lin[i].x2==lin[j].x1&&lin[i].y2==lin[j].y1&&lin[i].x1!=lin[i].x2)//往右边加线段 
			{
				lin[i].x2=lin[j].x2;
				lin[i].y2=lin[j].y2;
			    lin[i].len ++;
			    lin[j].x1=0;
			    lin[j].x2=0;
			    lin[j].len=0;
			}
			else
			continue;
		}
	}
	qsort(lin,n,sizeof(struct dot),cmp);
	printf("%d %d %d",lin[0].len,lin[0].x1,lin[0].y1);
}
//10
//80 75 125 75
//60 40 80 55
//80 55 90 20
//140 120 195 205
//10 111 70 165
//22 35 43 43
//22 175 80 205
//43 43 60 40
//90 20 125 60
//70 165 140 120

