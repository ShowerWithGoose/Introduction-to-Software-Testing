#include <stdio.h>

int n;
int vis[100];
int b[100];
void dfs(int x)
{
	int i,d;
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			b[x]=i;
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

