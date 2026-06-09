#include<stdio.h>
#include<string.h>
int a[11];int v[11],n;
void dfs(int x)
{
	if(x==n+1)
	{
		int i;
		for(i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	else
	{
		int i;
		for(i=1;i<=n;i++)
		{
			if(v[i]==1) continue;
			v[i]=1;
			a[x]=i;
			dfs(x+1);
			v[i]=0;a[x]=0;
		}
	}
}
int main()
{
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	memset(v,0,sizeof(v));
	dfs(1);
	return 0;
}



