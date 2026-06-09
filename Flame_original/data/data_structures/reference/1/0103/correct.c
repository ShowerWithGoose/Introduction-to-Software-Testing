#include <stdio.h> 
void dfs(int k);
char a[10];
char ans[10];
int sum=1,n;
int main()
{
	scanf("%d",&n);
	int cnt=1;
	for(;cnt<=n;cnt++)
		sum*=cnt;
	dfs(0);
	return 0; 
}
void dfs(int k)
{
	int cnt=0;	
	if(k==n)
	{
		for(cnt=0;cnt<n-1;cnt++)
			printf("%d ",ans[cnt]);
		printf("%d",ans[n-1]);
		sum--;
		if(sum!=0)
			printf("\n");
		return;
	}
	for(cnt=0;cnt<n;cnt++)
		if(a[cnt]==0)
		{
			ans[k]=cnt+1;	
			a[cnt]=1;
			dfs(k+1);
			a[cnt]=0;
		}	
}

