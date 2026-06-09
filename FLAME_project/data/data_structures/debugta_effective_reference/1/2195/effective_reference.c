#include<stdio.h>
#include<stdlib.h>

void again(int *ans,int a,int b){
	int i;
	int k=ans[b];
	for(i=b;i>a;i--){
		ans[i]=ans[i-1];
	}
	ans[a]=k;
}
void reagain(int *ans,int a,int b){
	int i;
	int k=ans[a];
	for(i=a;i<b;i++){
		ans[i]=ans[i+1];
	}
	ans[b]=k;
}
void C(int *ans,int a,int n){
	int i;
	if(a>n){
		for(i=0;i<=n;i++){
			printf("%d ",ans[i]);
		} 
		printf("\n");
	}
	else{
		for(i=a;i<=n;i++){
			again(ans,a,i);
			C(ans,a+1,n);
			reagain(ans,a,i);
		}
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	int *ans=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		ans[i]=i+1;
	}
	C(ans,0,n-1);
	free(ans);
	return 0;
} 

