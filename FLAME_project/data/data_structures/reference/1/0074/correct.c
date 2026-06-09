#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int n,i;
void dfs(int a[], int b[], int n , int depth){
	int i;
	if(depth==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1; 
			a[depth]=i;
			dfs(a,b,n,depth+1);
			b[i]=0;
		}
	}
}
int main(){	
	int a[100]={};
	int b[100]={};
	scanf("%d",&n);
	dfs(a,b,n,1);
	return 0;
}

