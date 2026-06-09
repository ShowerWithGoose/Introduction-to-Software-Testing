#include<stdio.h>
int i;
int a[1000];
int o[1000];
int n;
void dfs(int);
int main(){
	scanf("%d",&n);
    dfs(1);	
} 
void dfs(int deep){
	if(deep==n+1){
		int i;
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	int i;
	for(i=1;i<=n;i++){
		if(o[i]==0){
			a[deep]=i;
			o[i]=1;
			dfs(deep+1);
			o[i]=0;
		}
	}
}




