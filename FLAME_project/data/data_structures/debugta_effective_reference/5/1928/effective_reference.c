#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct d{
	long long xishu;
	long long zhishu;
};
int f(struct d *a,struct d *b)
{
	return b->zhishu-a->zhishu;
}
int main()
{
	char a;
	int i=0,j=0,q;
	struct d d1[100],d2[100];
	for(int i=0;i<2;)
	{
		if(i==0)
		{
		scanf("%lld %lld",&d1[i].xishu,&d1[i].zhishu);
		i++;
		}
		
		if(i==1)
		{
		scanf("%lld %lld",&d2[j].xishu,&d2[j].zhishu);
		j++;
		}
		a=getchar();
		if(a=='\n')
		i++;
	}
	struct d ans[1000];
	int k=0,p=0;
	for(;k<i;k++)
	{
		for(p=0;p<j;p++)
		{
			ans[q].xishu=d1[k].xishu*d2[p].xishu;
			ans[q].zhishu=d1[k].zhishu+d2[p].zhishu;
			q++;
		}
	}
	qsort(ans,q,sizeof(struct d),f);
	ans[q].xishu=0,ans[q].zhishu=-1;
	for(int i=0;i<q;i++)
	{
		if(ans[i].zhishu==ans[i+1].zhishu)
		ans[i+1].xishu+=ans[i].xishu;
		else
		printf("%d %d ",ans[i].xishu,ans[i].zhishu);
	}
	return 0;
}



