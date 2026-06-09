#include <stdio.h>
#include <stdlib.h>
struct multi
{
	long long xishu;
	long long cishu;
};
struct multi info1[1000000];
struct multi info2[1000000];
struct multi info3[1000000];
int main()
{
	int i=0,j=0,k,l,m;
	char c=' ';
	while(c!='\n')
	{
		scanf("%lld%lld%c",&info1[i].xishu,&info1[i].cishu,&c);
		i++;
	}
	c=' ';
	while(c!='\n')
	{
		scanf("%lld%lld%c",&info2[j].xishu,&info2[j].cishu,&c);
		j++;
	}
	m=0;
	for(k=0;k<i;k++)//计算 
	{
		for(l=0;l<j;l++)
		{
			info3[m].cishu=info1[k].cishu+info2[l].cishu;
			info3[m].xishu=info1[k].xishu*info2[l].xishu;
			m++;
		}
	}
	struct multi temp;
	for(i=0;i<m;i++)//排序 
	{
		for(j=i+1;j<m;j++)
		{
			if(info3[i].cishu<info3[j].cishu)
			{
				temp=info3[i];
				info3[i]=info3[j];
				info3[j]=temp;
			}
		}	
	}	
	/*for(i=0;i<m;i++)
	{
		printf("%d %d ",info3[i].xishu,info3[i].cishu);
	}
	printf("\n");*/
	for(i=0;i<m-1;i++)//系数相同的项 
	{
		if(info3[i].cishu==info3[i+1].cishu&&info3[i].cishu!=0)
		{
			/*info3[i].xishu=info3[i].xishu+info3[i+1].xishu;
			for(j=i+1;j<m;j++)
			{
				info3[j]=info3[j+1];
			}
			m--;*/
			info3[i+1].xishu+=info3[i].xishu;
			info3[i].xishu=0;
		}
	}
	for(i=0;i<=m;i++)
	{
		if(info3[i].xishu!=0)
		printf("%lld %lld ",info3[i].xishu,info3[i].cishu);
	}
	return 0;
}
/*123 346 3456 123 1344 54 678 34 1345 1 134 0
23452 123 562 56 567 23 535763 4 4567 2*/



