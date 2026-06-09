#include<stdio.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int a[200],b[200];
int cmp(const void *p1,const void *p2);
int cmp2(const void *p1,const void *p2);
int main()
{
	int i,j,n,num=1;
	struct line sort[200];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&sort[i].x1,&sort[i].y1,&sort[i].x2,&sort[i].y2);
	}
	qsort(sort,n,sizeof(struct line),cmp);
	for(i=0;i<n;i++)
	{
		num=1;
		for(j=i+1;j<n;j++)
		{
			if(sort[i].x2==sort[j].x1&&sort[i].y2==sort[j].y1)
			{
				num++;
				sort[i].x2=sort[j].x2;
				sort[i].y2=sort[j].y2;
			}
		}
		a[i]=num;
	}
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	qsort(a,n,sizeof(int),cmp2);
	printf("%d ",a[n-1]);
	for(i=0;i<n;i++)
	{
		if(b[i]==a[n-1])
		printf("%d %d",sort[i].x1,sort[i].y1);
	}
	return 0;
}
int cmp(const void *p1,const void *p2)
{
	struct line *a=(struct line *)p1;
	struct line *b=(struct line *)p2;
	return ((*a).x1-(*b).x1);
}
int cmp2(const void *p1,const void *p2)
{
	int *a=(int *)p1;
	int *b=(int *)p2;
	return (*a-*b);
}

