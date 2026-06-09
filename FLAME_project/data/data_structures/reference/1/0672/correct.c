#include<stdio.h>
int a[11],n,b[11];
void dfs(int deep)
{
	int i;
	if(deep==n+1)
	{
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[deep]=i;
			dfs(deep+1);
			b[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
}

