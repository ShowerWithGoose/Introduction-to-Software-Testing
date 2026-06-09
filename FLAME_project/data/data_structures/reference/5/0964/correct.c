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
	int k=0,j=0,t;
	struct d d1[100],d2[100];
	for(int i=0;i<2;)
	{
		if(i==0)
		{
		scanf("%lld %lld",&d1[k].xishu,&d1[k].zhishu);
		k++;
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
	int k1=0,j1=0;
	for(;k1<k;k1++)
	{
		for(j1=0;j1<j;j1++)
		{
			ans[t].xishu=d1[k1].xishu*d2[j1].xishu;
			ans[t].zhishu=d1[k1].zhishu+d2[j1].zhishu;
			t++;
		}
	}
	qsort(ans,t,sizeof(struct d),f);
	ans[t].xishu=0,ans[t].zhishu=-1;
	for(int i=0;i<t;i++)
	{
		if(ans[i].zhishu==ans[i+1].zhishu)
		ans[i+1].xishu+=ans[i].xishu;
		else
		printf("%d %d ",ans[i].xishu,ans[i].zhishu);
	}
	return 0;
}



