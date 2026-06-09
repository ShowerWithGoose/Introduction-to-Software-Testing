#include<stdio.h>
#include<ctype.h>
#include<string.h>
int used[15],vis[15];
void dfs(int k,int n){
	int i;
	if (k==n){
		for (i=0;i<n;i++){
			printf("%d ",used[i]);
		}
		printf("\n");
		return;
	}
	for (i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;
			used[k]=i;
			dfs(k+1,n);
			vis[i]=0;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	dfs(0,n);
	
	
	return 0;
}



