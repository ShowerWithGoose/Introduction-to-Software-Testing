#include<stdio.h>
int n,j=0;
int vis[50];
int a[100];
void dfs(int x,int num)
{
	int i,m,ans;
	ans=num;
	if(x==n+1)
	{
		for(m=0;m<n;m++)
		{
			a[m]=ans%10;
			ans=(ans-ans%10)/10;
		}
		for(j=n-1;j>=0;j--)
		printf("%d ",a[j]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(x+1,num*10+i);
			vis[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1,0);
	return 0;
}

