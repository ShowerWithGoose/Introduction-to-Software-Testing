#include <stdio.h>
#include <string.h>

#define MAXN 20

int n,way[MAXN],flag[MAXN]; 

void dfs(int k)
{
	if(k>n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",way[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
//		printf("i=%d\n",i);
		if(flag[i])
		{
			way[k-1]=i;
			flag[i]=0;
			dfs(k+1);
			flag[i]=1; 
		}
	}
}

int main()
{
	scanf("%d",&n);
	memset(flag,1,sizeof(flag));
	dfs(1);
	return 0;
}

