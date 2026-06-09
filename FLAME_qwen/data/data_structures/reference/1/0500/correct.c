#include<stdio.h>
int n, a[15],b[15];
void dfs(int step); 
int main()
{
	scanf("%d",&n);
	dfs(1);
	getchar();getchar();
	return 0;
 } 
void dfs(int step)
{	
	int i;
	if(step==n+1)
	{
		for(i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
	if(b[i]==0)
	{
		a[step]=i;
		b[i]=1;
		dfs(step+1);
		b[i]=0;
	}
}
		return;
	}

