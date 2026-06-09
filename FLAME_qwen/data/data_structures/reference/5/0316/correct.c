#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct Duo{
	int zhishu;
	int xishu;
};
comp(struct Duo *p1,struct Duo *p2)
{	
	if(p1->zhishu>p2->zhishu)
	return -1;
	else 
	return 1;
}
int main()
{
	int i=0;
	int j=0;
	int k=0;
	int z=0;
	int lon1,lon2;
	int count[25000];
	int sum[25000];
	int flag=0;
	struct Duo A1[500],A2[500],temp[25000],result[25000];
	for(i=0;i<500;i++)
	{
		scanf("%d %d",&(A1[i].xishu),&(A1[i].zhishu));
		if(getchar()=='\n')
		break;
	}
	lon1=i;
	for(j=0;j<500;j++)
	{
		scanf("%d %d",&(A2[j].xishu),&(A2[j].zhishu));
		if(getchar()=='\n')
		break;
	}
	lon2=j;
	for(i=0;i<=lon1;i++)
	{
		for(j=0;j<=lon2;j++)
		{
			temp[k].xishu=A1[i].xishu*A2[j].xishu;
			temp[k].zhishu=A1[i].zhishu+A2[j].zhishu;
			count[z++]=A1[i].zhishu+A2[j].zhishu;
			k++;
		}
	}
	for(i=0;i<z;i++)
	{	
		flag=0;
		for(j=0;j<i;j++)
		{
			if(count[i]==count[j])
			flag=1;
		}
		if(flag!=1)
		sum[i]=count[i];
	}
	for(i=0;i<z;i++)
	{
		for(j=0;j<k;j++)
		{
			if(temp[j].zhishu==sum[i])
			{
				result[i].xishu+=temp[j].xishu;
				result[i].zhishu=sum[i];
				
			}
		}
	}
	qsort(result,z,sizeof(result[0]),comp);
	for(i=0;i<z;i++)
	{
		if(result[i].xishu!=0)
		printf("%d %d ",result[i].xishu,result[i].zhishu);
	}
	return 0;
 } 


