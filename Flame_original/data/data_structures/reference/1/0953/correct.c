#include<stdio.h>
int mark[15],a[15];
void dfs(int n,int step){
		
	if(step==n){
		for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(mark[i]!=1){
		mark[i]=1;
		a[step]=i;
		dfs(n,step+1);
		mark[i]=0;
		}
	}
}
int main(){
	int n;
	for(int i=0;i<=14;i++)
		mark[i]=0;
	scanf("%d",&n);
	dfs(n,0);
	return 0;
} 



