#include<stdio.h>
int n,a[15],v[15];
void dfs(int x)
{
	int i;
	if(x==n+1)
	{
		for(i=1;i<=n;i++) printf("%d ",a[i]);
		putchar('\n');
		return ; 
	}
	for(i=1;i<=n;i++)
	if(!v[i])
	{
		v[i]=1;
		a[x]=i;
		dfs(x+1);
		v[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
}



