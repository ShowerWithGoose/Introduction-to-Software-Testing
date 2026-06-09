#include<stdio.h>
int n;
int a[10];
int b[10];
void dfs(int m)//深度搜索n元排列
{
	if(m>=n)
	{
		for(int i=0;i<n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	else
		for(int i=1;i<=n;i++)
			if(!a[i])
			{
				b[m]=i;
				a[i]=1;
				dfs(m+1);
				a[i]=0;
			}
}
int main()
{
	
	scanf("%d",&n); 
	dfs(0);
}

