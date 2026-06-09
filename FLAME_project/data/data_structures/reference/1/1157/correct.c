#include<stdio.h>

int vis[10];
int n;
int ans[10];
void work(int num)
{
	if(num==n)
	{
		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans[num]=i;
			vis[i]=1;
			work(num+1) ;
			vis[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	work(0);
	return 0;	
}
