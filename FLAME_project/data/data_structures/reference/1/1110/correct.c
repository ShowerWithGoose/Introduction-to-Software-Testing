#include<stdio.h>
int book[11];
int n;
int number[11];
void dfs(int x){
	int i;
	if(x==n){
		for(i=0;i<n;i++){
			printf("%d ",number[i]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			number[x]=i;
			dfs(x+1);
			book[i]=0;
		}
	}
	
}
int main(){
	scanf("%d",&n);
	dfs(0);
}



