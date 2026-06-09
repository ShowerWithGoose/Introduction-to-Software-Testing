#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int a,b;
}ab;
ab a[2][1000],ans[100000];
int cnt[3];
int cmp(const void *a,const void *b)
{
	ab *c=(ab*)a,*d=(ab*)b;
	if(c->b>d->b)	return -1;
	return c->b<d->b;
}
int main()
{
	for(int i=0;i<2;++i)
	{
		do{
			scanf("%d%d",&a[i][cnt[i]].a,&a[i][cnt[i]].b);
			++cnt[i];
		}while(getchar()!=10);
	}
	for(int i=0;i<cnt[0];++i)
		for(int j=0;j<cnt[1];++j)
		{
			ans[cnt[2]].a=a[0][i].a*a[1][j].a;
			ans[cnt[2]].b=a[0][i].b+a[1][j].b;
			++cnt[2];
		}
	qsort(ans,cnt[2],sizeof(ab),cmp);
	ans[cnt[2]++].b=-1;
	int k=ans[0].b,ci=0;
	for(int i=0,a,b;i<cnt[2];i++)
	{
		if(ans[i].b!=k)
		{
			a=0;
			b=ans[ci].b;
			for(int j=ci;j<i;j++)	a+=ans[j].a;
			printf("%d %d ",a,b);
			k=ans[i].b;
			ci=i;
		}
	}
	return 0;
}

