#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct Node
{
	int co,index;
	int flag;
}Num;
Num num1[MAX];
Num num2[MAX];
Num ans[MAX];
Num tmp;
int main()
{
	int i=0,j=0,cnt1=1,cnt2=1,cnt=0,m;
	char temp;
	while(scanf("%d%d%c",&num1[cnt1].co,&num1[cnt1].index,&temp))
	{
		cnt1++;
		if(temp=='\n')break;
	}
	cnt1--;
	while(scanf("%d%d%c",&num2[cnt2].co,&num2[cnt2].index,&temp))
	{
		cnt2++;
		if(temp=='\n')break;
	}
	cnt2--;
	//for(i=1;i<=cnt1;i++)printf("%d %d ",num1[i].co,num1[i].index);
	//puts("");
	//for(i=1;i<=cnt2;i++)printf("%d %d ",num2[i].co,num2[i].index);
	//puts("");
	for(i=1;i<=cnt1;i++)
	{
		for(j=1;j<=cnt2;j++)
		{
			++cnt;
			ans[cnt].co=num1[i].co*num2[j].co;
			ans[cnt].index=num1[i].index+num2[j].index;
			ans[cnt].flag=0;
		}
	}
	//for(i=1;i<=cnt;i++)printf("%d %d ",ans[i].co,ans[i].index);
	puts("");
	for(i=1;i<=cnt;i++)
	{
		for(j=1;j<=cnt-1;j++)
		{
			if(ans[i].index>ans[j].index)
			{
				tmp=ans[i];
				ans[i]=ans[j];
				ans[j]=tmp;
			}
		}
	}
	for(i=1;i<=cnt-1;i++)
	{
		if(ans[i].index==ans[i+1].index)
		{
			ans[i].flag=1;
			ans[i+1].co+=ans[i].co;
		} 
	}
	//for(i=1;i<=cnt;i++)printf("%d %d ",ans[i].co,ans[i].index);
	for(int i=1;i<=cnt;i++)
	{
		if(!ans[i].flag)printf("%d %d ",ans[i].co,ans[i].index);
	}
	//printf("%d %d ",ans[cnt].co,ans[cnt].index);
	return 0;
}


