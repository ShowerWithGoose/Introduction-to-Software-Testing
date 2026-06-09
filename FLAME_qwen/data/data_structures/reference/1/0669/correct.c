#include<stdio.h>
int n,ans[15],sym[15];
void dfs(int k)
{
	if(k==n)
	{
		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");
		return ;		
	} 
	for(int i=1;i<=n;i++)
	{
		if(sym[i]==0)
		{
			sym[i]=1;
			ans[k]=i;
			dfs(k+1);
			sym[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(0);
}



