#include<stdio.h>
#include<stdlib.h>
struct mult{
	int xishu;
	int zhishu;
}part1[200],part2[200],ans[40000];

int cmp(const void *a,const void *b)
{
	if((*(struct mult*)a).zhishu>(*(struct mult*)b).zhishu)
		return -1;
	else if((*(struct mult*)a).zhishu<(*(struct mult*)b).zhishu)
		return 1;
	else
		return 0;
}

int main()
{
	char flag;
	scanf("%d %d",&part1[1].xishu,&part1[1].zhishu);
	int i=1;
	while((flag = getchar())!='\n')
	{
		i++;
		scanf("%d %d",&part1[i].xishu,&part1[i].zhishu);
	}
	scanf("%d %d",&part2[1].xishu,&part2[1].zhishu);
	int j=1;
	while((flag = getchar())!='\n')
	{
		j++;
		scanf("%d %d",&part2[j].xishu,&part2[j].zhishu);
	}
	int count1=i,count2=j;
	int k=0;
	for(i=1;i<=count1;i++)
	{
		for(j=1;j<=count2;j++)
		{
			k++;
			ans[k].xishu = part1[i].xishu*part2[j].xishu;
			ans[k].zhishu = part1[i].zhishu+part2[j].zhishu;
		}
	}
	int num=k;
	for(i=1;i<=num;i++)
	{
		for(j=i+1;j<=num;j++)
		{
			if(ans[i].zhishu==ans[j].zhishu)
			{
				ans[i].xishu = ans[i].xishu + ans[j].xishu;
				ans[j].xishu = 0;
				ans[j].zhishu = 0;
			}
		}
	}
	struct mult *p = &ans[1];
	qsort(p,num,sizeof(ans[1]),cmp);
	for(k=1;k<=num;k++)
	{
		if(ans[k].xishu != 0)
		{
			printf("%d %d ",ans[k].xishu,ans[k].zhishu);
		}
	}
	return 0;
}



