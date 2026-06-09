#include<stdio.h>
#include<stdlib.h>
struct node
{
	int xishu,zhishu;
}dxs1[105],dxs2[105],ans[10005];
int cmp(const void *a0,const void *b0)
{
	struct node a=*((struct node*)a0);
	struct node b=*((struct node*)b0);
	if(a.zhishu>b.zhishu)
		return -1;
	else
		return 1;
}
int main()
{
	int i=0,j=0,k=0,l;
	char c;
	do
	{
		scanf("%d%d%c",&dxs1[i].xishu,&dxs1[i].zhishu,&c);
		i++;
	}while(c!='\n');
	do
	{
		scanf("%d%d%c",&dxs2[j].xishu,&dxs2[j].zhishu,&c);
		j++;
	}while(c!='\n');
	int l1=i,l2=j;
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			ans[k].xishu=dxs1[i].xishu*dxs2[j].xishu;
			ans[k].zhishu=dxs1[i].zhishu+dxs2[j].zhishu;
			k++;
		}
	}
	int l3=k;
	for(k=0;k<l3;k++)
	{
		for(l=k+1;l<l3;l++)
		{
			if(ans[l].zhishu==ans[k].zhishu)
			{
				ans[k].xishu+=ans[l].xishu;
				ans[l].xishu=0;
				ans[l].zhishu=-1;
			}
		}
	}
	qsort(ans,l3,sizeof(ans[0]),cmp);
	for(i=0;i<l3;i++)
		if(ans[i].xishu!=0&&ans[i].zhishu!=-1)
			printf("%d %d ",ans[i].xishu,ans[i].zhishu);
	return 0;
}

