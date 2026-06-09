#include<stdio.h>
int n,flag[10]={0},num[10]={0};
void print(){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}
void dfs(int k){
	int i;
	if(k==n){
		print();
		return;
	}
	for(i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			num[k+1]=i;
			dfs(k+1);
			flag[i]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}



