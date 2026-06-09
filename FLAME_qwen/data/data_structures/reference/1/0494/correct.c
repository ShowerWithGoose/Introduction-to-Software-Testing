#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define NUM 1
#define LOW 2
#define CAP 3
int n,j;
bool f[15];
int num[15];
void dfs(int deep){
	if(deep==n){
		for(j=0;j<n;j++){
			printf("%d",num[j]);
			if(j<n-1)printf(" ");
		}
		printf("\n");
		return;
	}
	int i;
	for(i=1;i<=n;i++){
		if(!f[i]){
			num[deep]=i;
			f[i]=1;
			dfs(deep+1);
			f[i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}


