#include<stdio.h>
#include<math.h>
#include<string.h>
int dfs(int a[],int b[],int n,int depth);
int dfs(int a[],int b[],int n,int depth){
	if(depth==n+1){
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return 1 ;
	}
	
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			a[depth]=i;
			dfs(a,b,n,depth+1);
			b[i]=0;
		}
	}
	
}
int main(){
int a[10]={0},b[10]={0};
	int n;
	scanf("%d",&n);
	dfs(a,b,n,1);
		
	
	return 0;
}



