#include<stdio.h>
int n;
int book[11],ans[11];
void dfs(int step);
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}
void dfs(int step)
{
	int i;
	if(step==n+1)
	{
		printf("%d",ans[1]);
		for(i=2;i<=n;i++)
		{
			printf(" %d",ans[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			ans[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return ;
}

