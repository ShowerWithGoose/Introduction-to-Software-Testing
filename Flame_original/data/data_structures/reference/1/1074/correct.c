#include <stdio.h>
int hash[20];
int a[20];
void dfs(int n,int cnt)
{
	if(cnt<=n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!hash[i])
			{
				a[cnt]=i;
				hash[i]=1;
				dfs(n,cnt+1);
				hash[i]=0;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(n,1);
	return 0;
	
}



