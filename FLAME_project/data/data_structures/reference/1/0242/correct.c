#include<stdio.h>
int n,pd[100],used[100];
void print()
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",used[i]);
	}
	printf("\n");
	return;
}
void dfs(int k)
{
	int i;
	if(k==n)
	{
		print();
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(pd[i]==0)
		{
			pd[i]=1;
			used[k+1]=i;
			dfs(k+1);
			pd[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}

