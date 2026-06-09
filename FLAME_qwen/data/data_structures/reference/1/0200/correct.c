#include <stdio.h>
#include <string.h>
int a[10];
int b[10];
void f(int n,int k){
	int i,j;
	if(k==n){
		for(i=0;i<n;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	else{
		for(j=1;j<=n;j++){
		if(a[j]!=1){
			b[k]=j;
			a[j]=1;
			f(n,k+1);
			a[j]=0;
		}}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	f(n,0);
	return 0;
}




