#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Duoxiangshi
{
	int xishu;
	int zhishu;
}p1[1000],p2[1000],sum[1000000];
int cmp(const void*p1,const void*p2)
{
	struct  Duoxiangshi*c=(struct Duoxiangshi*)p1;
	struct  Duoxiangshi*d=(struct Duoxiangshi*)p2;
	if(c->zhishu <= d->zhishu) 
		return 1;
	return -1; 
}
int main()
{
	int p=0,q=0,pp,pq,prod=0,flag1,flag2;
	while(scanf("%d %d",&p1[p].xishu,&p1[p].zhishu)!=EOF)
	{
		p++;
		if(getchar()=='\n')
			break;
	}
	while(scanf("%d %d",&p2[q].xishu,&p2[q].zhishu)!=EOF)
	{
		q++;
		if(getchar()=='\n')
			break;
	}
	for(pp=0;pp<p;pp++)
	{
		for(pq=0;pq<q;pq++)
		{
			sum[prod].xishu=p1[pp].xishu*p2[pq].xishu;
			sum[prod].zhishu=p1[pp].zhishu+p2[pq].zhishu;
			prod++;
		}
	}
	qsort(sum,prod,sizeof(sum[0]),cmp);
	for(p=0;p<prod;p++)
	{
		if(sum[p].zhishu==sum[p+1].zhishu)
		{
			sum[p+1].xishu=sum[p].xishu+sum[p+1].xishu;
			sum[p].xishu=0;
			sum[p].zhishu=0;
		}
	}
	for(p=0;p<=prod;p++)
	{
		if(sum[p].xishu!=0)
		{
			printf("%d %d ",sum[p].xishu,sum[p].zhishu);
		}
	}
	return 0;
}

