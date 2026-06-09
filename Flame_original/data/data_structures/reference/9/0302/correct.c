#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line
{
	int x1,y1,x2,y2;
	int flag;
	int time;
};
int cmp1(const void *a,const void *b)
{
	struct line *aa=(struct line *)a;
	struct line *bb=(struct line *)b;
	return ((aa->x1)-(bb->x1));
}
int cmp2(const void *a,const void *b)
{
	struct line *aa=(struct line *)a;
	struct line *bb=(struct line *)b;
	return ((aa->flag)-(bb->flag));
}
int main()
{
	int n,i,j;
	struct line l[114];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].flag=1;
	}
	qsort(l,n,sizeof(l[0]),cmp1);
	for(i=0;i<n;i++)
	{
		int m=i;
		if(l[i].flag!=1)
			continue;
		for(j=0;j<n;j++)
		{
			if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)
			{
				l[m].flag++;
				i=j;
				j=-1;
			}
		}
	}
	qsort(l,n,sizeof(l[0]),cmp2);
	printf("%d %d %d\n",l[n-1].flag,l[n-1].x1,l[n-1].y1);
}
/* 10 10 2 2
10 10 30 30
30 30 60 60
4 4 10 10
3 3 4 4*/


