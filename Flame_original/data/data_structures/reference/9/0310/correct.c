#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct zuobiao{ 
	int x1,x2,y1,y2;
	int cnt;
}a[1010];
typedef struct zuobiao *cmp;
int f1(const void *a,const void *b)
{
	cmp p=(cmp)a;
	cmp q=(cmp)b;
	if(p->x1==q->x1)	return p->y1-q->y1;
	else	return p->x1-q->x1;
}
int f2(const void *a,const void *b)
{
	cmp p=(cmp)a;
	cmp q=(cmp)b;
	return p->cnt-q->cnt;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	for(i=0;i<n;i++)
		a[i].cnt=1;
	qsort(a,n,sizeof(a[0]),f1);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(j==i)	continue;
			else
			{
				if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
				{
					a[i].x2=a[j].x2;
					a[i].y2=a[j].y2;
					a[i].cnt+=a[j].cnt;
					a[j].cnt=0;
					a[j].x1=0;
					a[j].x2=0;
					a[j].y1=0;
					a[j].y2=0;
				}
			}
		}
	}
	qsort(a,n,sizeof(a[0]),f2);
	printf("%d %d %d",a[n-1].cnt,a[n-1].x1,a[n-1].y1);
	return 0;
}

