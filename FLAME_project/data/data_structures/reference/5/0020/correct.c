#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Duoxiangshi
{
	int xishu;
	int zhishu;
}a[1000],b[1000],sum[1000000];
int cmp(const void*a,const void*b)
{
	struct  Duoxiangshi*c=(struct Duoxiangshi*)a;
	struct  Duoxiangshi*d=(struct Duoxiangshi*)b;
	if(c->zhishu <= d->zhishu) 
		return 1;
	return -1; 
}
int main()
{
	int i=0,j=0,k,t,n=0,flag1,flag2;
	while(scanf("%d %d",&a[i].xishu,&a[i].zhishu)!=EOF)
	{
		i++;
		if(getchar()=='\n')
			break;
	}
	while(scanf("%d %d",&b[j].xishu,&b[j].zhishu)!=EOF)
	{
		j++;
		if(getchar()=='\n')
			break;
	}
	for(k=0;k<i;k++)
	{
		for(t=0;t<j;t++)
		{
			sum[n].xishu=a[k].xishu*b[t].xishu;
			sum[n].zhishu=a[k].zhishu+b[t].zhishu;
			n++;
		}
	}
	qsort(sum,n,sizeof(sum[0]),cmp);
	for(i=0;i<n;i++)
	{
		if(sum[i].zhishu==sum[i+1].zhishu)
		{
			sum[i+1].xishu=sum[i].xishu+sum[i+1].xishu;
			sum[i].xishu=0;
			sum[i].zhishu=0;
		}
	}
	for(i=0;i<=n;i++)
	{
		if(sum[i].xishu!=0)
		{
			printf("%d %d ",sum[i].xishu,sum[i].zhishu);
		}
	}
	return 0;
}

