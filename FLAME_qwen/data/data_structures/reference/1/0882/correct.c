#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void dfs(int,int);

int num[150],fl[105];

int main()
{
	int n;
	scanf("%d",&n);
	dfs(n,1);
	return 0;
}

void dfs(int n,int dep)
{
	int i;
	if(dep>n)
	{
		for(i=1;i<=n;i++)
		printf("%d ",num[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(fl[i]!=1)
		{
			fl[i]=1;
			num[dep]=i;
			dfs(n,dep+1);
			fl[i]=0;
		}
	}
	return;
}



