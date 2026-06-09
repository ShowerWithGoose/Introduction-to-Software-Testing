#include<stdio.h>
#include<stdlib.h>
int n;
int v[15],a[15];
void dfs(int k){
	if(k==n+1){
		int i=1;
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	int i;
	for(i=1;i<=n;i++){
		if(v[i])continue;
		a[k]=i;v[i]=1;
		dfs(k+1);
		v[i]=0;
	}
	return ;
}
int main(){
	scanf("%d",&n);
	dfs(1);
	return 0;
}

