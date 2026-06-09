#include<stdio.h>
int N,A[11],mk[11];
void dfs(int n){
	int i;
	if(n>N){
		for(i=1;i<=N;i++)
		printf("%d%c",A[i],i==N?'\n':' ');
		return;
	}
	for(i=1;i<=N;i++){
		if(!mk[i]){
			mk[i]=1;
			A[n]=i;
			dfs(n+1);
			mk[i]=0;
		}
	}
}
int main(){
	scanf("%d",&N);
	dfs(1);
	return 0;
}

