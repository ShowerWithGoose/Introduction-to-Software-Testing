#include<stdio.h>
#include<string.h>
int a[100],occ[100];
void dfs(int n,int floor)
{
	int i;
	if(floor==n+1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(occ[i]) 
			continue;
		a[floor]=i;
		occ[i]=1;
		dfs(n,floor+1);
		occ[i]=0;
	}
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(n,1);
	return 0;
}

