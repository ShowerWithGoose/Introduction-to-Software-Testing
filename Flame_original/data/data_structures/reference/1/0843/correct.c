#include<stdio.h>

void f(int m,int n,int a[],int k[]){
	int temp;
	int i;
	if(m>n){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
			
		}
		printf("\n");
	}
	else{
		for(i=1;i<n+1;i++){
			if(k[i]==0){
				k[i]=1;
				a[m]=i;
				f(m+1,n,a,k);
				k[i]=0;
			}
			
		}
	}
}
int main(){
	int n,i,a[20];
	int k[20]={0};
	scanf("%d",&n);
	f(1,n,a,k);
	return 0;
}

