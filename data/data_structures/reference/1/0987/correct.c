#include<stdio.h>
int n;
int a[100];
int vis[100];
void dfs(int k)
{
	if(k>n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return ;
	}
	for(int h=1;h<=n;h++)
	{
		if(!vis[h])
		{
			vis[h]=1;
			a[k]=h;
			dfs(k+1);
			vis[h]=0;
			a[k]=0;
		}
	}
}



int main()
{
	
	scanf("%d",&n);
	dfs(1);
	
	return 0;
 } 

