#include<stdio.h>
#include<string.h>
void dfs(int m);
int n,pos[15],vis[15];
int main(){
	scanf("%d",&n);
	dfs(1);
	
	return 0;
}

void dfs(int m)
{
	if(m>n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",pos[i]);
		}
		printf("\n");
		return ;
	}
	for(pos[m]=1;pos[m]<=n;pos[m]++)
	{
		if(vis[pos[m]]==0)
		{
			vis[pos[m]]=1;
			dfs(m+1);
			vis[pos[m]]=0;
		}
		else continue;
	}
	return ;
}



