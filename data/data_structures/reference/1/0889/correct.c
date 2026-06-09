#include <stdio.h>
#include <math.h>
#include <string.h>
int n,a[11]={0},b[11];
void Printf()
{
	for(int i=1;i<=n;i++)
	printf("%d ",b[i]);
	printf("\n");
}
void dfs(int m)
{
	if(m>n)
	{
		Printf();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			a[i]=1;
			b[m]=i;
			dfs(m+1);
			a[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
 	return 0;
}


