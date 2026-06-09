#include<stdio.h>
int A[10]={},R[10]={},N;
void ORder(int m,int n);
int main(){
	scanf("%d",&N);
	ORder(0,N);
	return 0;
}
void ORder(int m,int n){
	int i;
	if(n==0){
		for(i=0;i<N;i++)
			printf("%d ",A[i]);
		putchar('\n');
	}
	else{
		for(i=0;i<N;i++){
			if(R[i]==0){
				R[i]=1;
				A[m]=i+1;
				ORder(m+1,n-1);
				R[i]=0;
			}
		}
	}
}


