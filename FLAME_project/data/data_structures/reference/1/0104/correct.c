#include<stdio.h>

int a[105],b[105],n;

void dfs(int o)
{
	if(o>n)
	{
		for(int i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!b[i])
		{
			a[o]=i;b[i]=1;
			dfs(o+1);
			b[i]=0;
		}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

