#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2);
struct line1{
	int x1;
	int y1;
	int x2;
	int y2;
};
typedef struct line1 l1;
struct line2{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
typedef struct line2 l2;
int main()
{
	l1 a[1000];
	l2 b[1000];
	int n,i,j,flag=0,t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(l1),cmp);
	for(i=0;i<n;i++)
	{
		b[i].x1=a[i].x1;
		b[i].x2=a[i].x2;
		b[i].y1=a[i].y1;
		b[i].y2=a[i].y2;
		b[i].num=1;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(b[i].x2==a[j].x1&&b[i].y2==a[j].y1)
				{
					b[i].x2=a[j].x2;
					b[i].y2=a[j].y2;
					b[i].num++;
				}
			}
		}
		if(b[i].num>t)
		{
			t=b[i].num;
			flag=i;
		}
	}
	printf("%d %d %d",t,b[flag].x1,b[flag].y1);
	return 0;	
}
int cmp(const void*p1,const void*p2)
{
	struct line1 *a=(struct line1*)p1;
	struct line1 *b=(struct line1*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1-b->y2;
}

