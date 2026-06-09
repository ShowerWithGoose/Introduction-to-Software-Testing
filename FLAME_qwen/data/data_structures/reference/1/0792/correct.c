#include<stdio.h>
#include<string.h>
int ans[20],book[20]={0};
int n;
void dfs(int step)
{
	int i;
	if(step==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
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
} 

int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}



