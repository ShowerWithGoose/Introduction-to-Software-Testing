#include<stdio.h>
int a[10];
int b[10];
int n;
void DFS(int depth){
	if(depth==n){
		for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++){
		if(b[i]==0){
			a[depth]=i+1;
			b[i]=1;
			DFS(depth+1);
			b[i]=0;
		}
	}
}
int main(){
	int depth=0;
	scanf("%d",&n);
	DFS(depth);
	return 0;
} 

