#include <stdio.h>
int n,a[20],h[10]={0};
void dfs(int x)
{
	int i,k;
	if(x==n)
	{
		for(i=1;i<=n;i++)
		{
			if(h[i]==0)
			{
				a[x]=i;
				for(k=1;k<=n;k++)
				{
					printf("%d ",a[k]);
				}
				printf("\n");
			}
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(h[i]==0)
			{
				a[x]=i;
				h[i]=1;
				dfs(x+1);
				h[i]=0;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
} 

