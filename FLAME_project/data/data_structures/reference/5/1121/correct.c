#include<stdio.h>
#include<stdlib.h>

struct d
{
	int xi;
	int zhi;
}x[10000],y[10000],sum[100000];

int cmp(const void *p1,const void *p2)
{
	struct d *a=(struct d *)p1,*b=(struct d *)p2;
	if(a->zhi>b->zhi)
	return -1;
	if(a->zhi<b->zhi)
	return 1;
}

int main()
{
	int i,j,k,ans1,ans2,cnt=0,flag;
	char c;
	i=0;j=0;
	while(1)
	{
		scanf("%d",&x[i++].xi);
		scanf("%d",&x[j++].zhi);
		scanf("%c",&c);
		if(c=='\n')
		break;
	}
	ans1=i;
	i=0;j=0;
	while(1)
	{
		scanf("%d",&y[i++].xi);
		scanf("%d",&y[j++].zhi);
		scanf("%c",&c);
		if(c=='\n')
		break;
	}
	ans2=i;
	for(i=0;i<ans1;i++)
	{
		for(j=0;j<ans2;j++)
		{
			flag=0;
			for(k=0;k<cnt;k++)
			{
				if(sum[k].zhi==x[i].zhi+y[j].zhi)
				{
					sum[k].xi=sum[k].xi+x[i].xi*y[j].xi;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				sum[cnt].xi=x[i].xi*y[j].xi;
				sum[cnt].zhi=x[i].zhi+y[j].zhi;
				cnt++;
			}
		}
	}
	qsort(sum,cnt,sizeof(sum[0]),cmp);
	for(i=0;i<cnt;i++)
	{
		if(sum[i].xi!=0)
		printf("%d %d ",sum[i].xi,sum[i].zhi);
	}
	return 0;
}

