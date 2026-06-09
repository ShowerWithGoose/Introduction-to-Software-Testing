#include<stdio.h>
#include<string.h>
struct shuru{
	int xishu[100];
	int zhishu[100];
}begin,began,ans,bid;
int main()
{
	int i=0;
	while (1) 
	{
		scanf("%d%d",&begin.xishu[i],&begin.zhishu[i]);
		char c=getchar();
		if(c=='\n')
		{
			break;
		}
		i++;
	}
	int j=0;
	while (1) 
	{
		scanf("%d%d",&began.xishu[j],&began.zhishu[j]);
		char c=getchar();
		if(c=='\n')
		{
			break;
		}
		j++;
	}
	int k=0,t=0,b=0;
	for(k=0;k<=i;k++)
	{
		for(t=0;t<=j;t++)
		{
			ans.xishu[b]=(begin.xishu[k]*began.xishu[t]);
			ans.zhishu[b]=(begin.zhishu[k]+began.zhishu[t]);
			b++;
		}
	}
	for(i=1;i<b;i++)
	{
		for(j=i+1;j<=b;j++)
		{
			if(ans.zhishu[i]<ans.zhishu[j])
			{
				bid.xishu[i]=ans.xishu[j];
				ans.xishu[j]=ans.xishu[i];
				ans.xishu[i]=bid.xishu[i];
				bid.zhishu[i]=ans.zhishu[j];
				ans.zhishu[j]=ans.zhishu[i];
				ans.zhishu[i]=bid.zhishu[i];
			}
			if(ans.zhishu[i]==ans.zhishu[j])
			{
				ans.xishu[i]=ans.xishu[i]+ans.xishu[j];
				ans.xishu[j]=0;
			}
		}
		
	}
	for(i=0;i<=b;i++)
	{
		
		if(ans.xishu[i]!=0)
		{
			printf("%d ",ans.xishu[i]);
			printf("%d ",ans.zhishu[i]);
		}
	}
}

