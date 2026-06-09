#include<stdio.h>
#include<string.h>
int M[11],ans[11],t;
void f(int n,int m){
	if(m==0){
		for(int i=0;i<t;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		return;
	}
	for(int j=1;j<=t;j++){
		if(M[j]==0){
			ans[n]=j;
			M[j]=1;
			f(n+1,m-1);
		M[j]=0;
		}
	}
}
int main(){
	scanf("%d",&t);
	f(0,t);
	return 0;
}



