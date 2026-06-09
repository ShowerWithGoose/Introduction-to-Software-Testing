#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int n,vis[15],in[15];
void dfs(int day)
{
	if(day >= n) 
	{
		for(int i=1;i<=n;i++) printf("%d ",in[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		
		vis[i] = 1;
		in[++in[0]] = i;
		
		dfs(day+1);
		
		in[0]--;
		vis[i] = 0;
	}
} 
int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}



