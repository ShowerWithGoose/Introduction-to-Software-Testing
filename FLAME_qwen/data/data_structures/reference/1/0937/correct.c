#include<stdio.h>
int num[15],used[15],n;
void dfs(int k)
{
	int i;
	if(k>n)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			num[k]=i;
			used[i]=1;
			dfs(k+1);
			used[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

