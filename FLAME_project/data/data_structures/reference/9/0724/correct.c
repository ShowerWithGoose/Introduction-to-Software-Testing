#include<stdio.h>
#include<stdlib.h>

struct Line_Segment{
	int xStart;
	int yStart;
	int xEnd;
	int yEnd;
	int num;
};
typedef struct Line_Segment LS;
LS a[100];

int i,j;

int cmp(const void *p1, const void *p2);
int cmp2(const void *p1, const void *p2);

int main(void)
{
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].xStart,&a[i].yStart,&a[i].xEnd,&a[i].yEnd);
	}
	qsort(a,n,sizeof(LS),cmp);
	for(i=0;i<n;i++)
	{
		a[i].num=1;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j].xStart==a[i].xEnd&&a[j].yStart==a[i].yEnd)
			{
				a[i].xEnd=a[j].xEnd;
				a[i].yEnd=a[j].yEnd;
				a[i].num++;
			}
		}
	}
	qsort(a,n,sizeof(LS),cmp2);
	printf("%d %d %d\n",a[n-1].num,a[n-1].xStart,a[n-1].yStart); 
	
	return 0;	
} 

int cmp(const void *p1, const void *p2)
{
	struct Line_Segment *a = (struct Line_Segment *)p1;
	struct Line_Segment *b = (struct Line_Segment *)p2;
	if(a->xStart!=b->xStart)
	{
		return a->xStart-b->xStart;			
	}
	else
	{
		return a->yStart-b->yStart;			
	}
}

int cmp2(const void *p1, const void *p2)
{
	struct Line_Segment *a = (struct Line_Segment *)p1;
	struct Line_Segment *b = (struct Line_Segment *)p2;
	return a->num-b->num;	
}

