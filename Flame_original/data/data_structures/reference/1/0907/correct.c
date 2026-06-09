#include<stdio.h>
int b[15];
int n;
int a[15];
void dfs(int p){
	if(p==n){
		for(int i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			a[p]=i;
			dfs(p+1);
			b[i]=0;
		}
	}
	return;
}
int  main(){
	scanf("%d",&n);
	dfs(0);
}
