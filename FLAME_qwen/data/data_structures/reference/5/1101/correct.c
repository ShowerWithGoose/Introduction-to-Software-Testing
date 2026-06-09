#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 2500
struct line{
	int di;
	int zhi;
};
typedef struct line L;
L p[N],q[N],r[N];
int cmp(const void*a,const void*b)
{
	struct line *c=(struct line*)a;
	struct line *d=(struct line*)b;
	return (d->zhi-c->zhi);
}
int main()
{
	int i,j;
	int k=0;
	int cnt_1=0,cnt_2=0;
	char c;
	do
	{
		scanf("%d%d%c",&p[cnt_1].di,&p[cnt_1].zhi,&c);
		cnt_1++;
	}while(c!='\n');
	qsort(p,cnt_1,sizeof(L),cmp);
	do
	{
		scanf("%d%d%c",&q[cnt_2].di,&q[cnt_2].zhi,&c);
		cnt_2++;
	}while(c!='\n');
	qsort(q,cnt_2,sizeof(L),cmp);
	for(i=0;i<cnt_1;i++)
	{
		for(j=0;j<cnt_2;j++)
		{
			r[k].di=p[i].di*q[j].di;
			r[k].zhi=p[i].zhi+q[j].zhi;
			k++;
		}
	}
	qsort(r,k,sizeof(L),cmp);
	for(i=0;i<k;i++)
	{
			if(r[i].zhi==r[i+1].zhi&&r[i].zhi!=0)
			{
				r[i+1].di+=r[i].di;
				r[i].di=0;
			}
	}
	qsort(r,k,sizeof(L),cmp);
	for(i=0;i<k;i++)
	{
		if(r[i].di!=0)
		{
			printf("%d %d ",r[i].di,r[i].zhi);
		}
	}
	return 0;
}

