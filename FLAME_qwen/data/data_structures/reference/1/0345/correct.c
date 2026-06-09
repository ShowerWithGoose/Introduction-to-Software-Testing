#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bool_[15];
int n;
int ans[15];
void dfs(int x){
	int i;
	if(x==n+1)//边界条件
	{ 
		for(i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		return;
	}
	
	for(i=1;i<=n;i++)
	{
		if(bool_[i]==0)
		{//还在手里 
			bool_[i]=1;
			ans[x]=i;
			dfs(x+1);
			bool_[i]=0;
		}
		
	}
	return;
	
}
int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}

