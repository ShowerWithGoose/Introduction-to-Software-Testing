#include<stdio.h>
int a[101],b[101];
void dfs(int n,int d)
{
	if(d==n+1)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[d]=i;
			dfs(n,d+1);
			b[i]=0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(n,1);
	return 0;
}

