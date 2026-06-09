#include<stdio.h>
#include<string.h>
#include<math.h>
int a[10000000],b[10000000],n;
void dfs(int c)
{
	int i;
	if(c==n+1)
	{
		for(i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			a[c]=i;
			b[i]=1;
			dfs(c+1);
			b[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
    dfs(1);
return 0;
}


