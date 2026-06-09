#include<stdio.h>
int N,a[11],used[11];
void dfs(int flag){
	if(flag==N+1){
		int i;
		for(i=1;i<=N;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	else{
		int i;
		for(i=1;i<=N;i++){
			if(used[i]==0){
				a[flag]=i;
				used[i]=1;
				dfs(flag+1);
				used[i]=0; 
			}
		}
	}
}
int main(){
	scanf("%d",&N);
	dfs(1);
	return 0;
}

