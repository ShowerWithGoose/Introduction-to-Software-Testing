#include<stdio.h>
#include<string.h>
int vis[11];
int num[11];
int sum;
int cnt;
int n;
void dfs(int ind)
{
	if(ind == n) {
		for(int i = 0; i < n; i++)
		printf("%d ",num[i]);
		cnt++;
		if(cnt!=sum)
	printf("\n");
	return;	
	}
	int i;
	for(i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			num[ind] = i;
			dfs(ind+1);
			vis[i ]= 0;
		}
	}
	
	return;
}
int main()
{
	scanf("%d",&n);
	int i;
	sum = 1;
	for(i = 1; i <= n; i++)
	sum*=i;
	for(i = 1; i <= n; i++)
	{
		vis[i] = 1;
		num[0] = i;
		dfs(1);
		vis[i] = 0;
	}
}
