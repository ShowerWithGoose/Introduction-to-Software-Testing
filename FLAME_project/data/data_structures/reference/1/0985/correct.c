#include<stdio.h>

int n;
int vis[15];
int a[15];

void dfs(int k)
{
	if(k==n)
	{
		for(int i=0;i<k;i++)
			printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
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
	dfs(0);
	return 0;
}

