#include<stdio.h>
#include<string.h>
int path[100];
int n;
int st[100]={0};
void dfs(int u)
{
	int i;
	
	if(u==n)
	{
		
		for(i=0;i<n;i++) printf("%d ",path[i]);
		puts(" ");
		return;
	}
	

		for(i=1;i<=n;i++){
		if(!st[i]){
		path[u]=i;
		st[i]=1;
		dfs(u+1);
		st[i]=0;
	}
	}
 } 
 
int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}



