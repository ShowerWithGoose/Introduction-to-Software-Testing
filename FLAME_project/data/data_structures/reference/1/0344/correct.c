#include<stdio.h>

int n;
int a[12],vis[12];

void dfs(int k)
{
	int i;
	if(k>n)
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

