#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 150
struct point{
	int dx1;
	int dy1;
	int dx2;
	int dy2;
	int cnt;
};
typedef struct point P;
P p[2500];
int n;
int cmp_first(const void*a,const void*b)
{
	struct point *c=(struct point*)a;
	struct point *d=(struct point*)b;
	if(c->dx1!=d->dx1)
	 return c->dx1-d->dx1;
	else
	 return c->dy1-d->dy1;
}
int cmp_second(const void*a,const void*b)
{
	struct point *c=(struct point*)a;
	struct point *d=(struct point*)b;
	return c->cnt-d->cnt;
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i].dx1,&p[i].dy1,&p[i].dx2,&p[i].dy2);
	}
	qsort(p,n,sizeof(P),cmp_first);
	for(i=0;i<n;i++)
	{
		p[i].cnt=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(p[j].dx1==p[i].dx2&&p[j].dy1==p[i].dy2)
				{
				    p[i].dx2=p[j].dx2;
					p[i].dy2=p[j].dy2;
				    p[i].cnt+=p[j].cnt;
					p[j].dx1=0;
					p[j].dy1=0;
					p[j].dx2=0;
					p[j].dy2=0;
					p[j].cnt=0;
				}
			}
		}
	}
	qsort(p,n,sizeof(P),cmp_second);
	printf("%d %d %d\n",p[n-1].cnt,p[n-1].dx1,p[n-1].dy1);
	return 0;
}

