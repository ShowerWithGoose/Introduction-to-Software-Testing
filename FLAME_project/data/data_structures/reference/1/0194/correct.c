#include<stdio.h>
int n;
int a[105],b[105];
void dfs(int k)
{	int i=0;
	if(k==n)
	{	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	if(b[i]==0)
	{	a[k]=i;
		b[i]=1;
		dfs(k+1);
		b[i]=0;
	}
} 
int main()
{	scanf("%d",&n);
	dfs(0);
	return 0;
}

