#include <stdio.h>
#include<math.h>
int n;
int vis[50];
int f(int n)
{
	if(n==0)
	return 1;
	else 
	return 10*f(n-1);
}
void dfs(int x,int num)
{
	int i,k;
	if(x==n+1)	//考虑完了n位数,再进一次时打印 
	{
		for(k=n;k-1>=0;k--)
		{
		printf("%d ",num/f(k-1));
		num=num%f(k-1);
	}
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

