#include<stdio.h>
int vis[100],ans[100];
int n;
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<x;i++)
		printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			ans[x]=i;
			dfs(x+1);
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



