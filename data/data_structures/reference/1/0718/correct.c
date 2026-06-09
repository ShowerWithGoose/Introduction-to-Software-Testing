#include<stdio.h>
int x[15]={};
int n;//不开全局变量在函数中无法直接调用 
void DFS(int l);
int test(int k,int l);
int main(){
	scanf("%d",&n);
	DFS(0);
	return 0; 
}
void DFS(int l){
	int i;
	if(l==n){
		for(i=0;i<n-1;i++){
			printf("%d ",x[i]);
		}
		printf("%d\n",x[n-1]);
		return;
	}
	for(i=1;i<=n;i++){
		if(test(i,l)==0){
			x[l]=i;
			DFS(l+1);
		}
	}
}
int test(int k,int l){
	int i;
	for(i=0;i<l;i++){
		if(x[i]==k)return 1;
	}
	return 0;
}


