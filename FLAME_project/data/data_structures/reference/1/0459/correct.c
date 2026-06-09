#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void f(int n,int a[],int k,int b[]){
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			continue;
		}
		a[i]=1;
		b[k]=i;
		if(k==n){
			for(int j=1;j<=n;j++){
				printf("%d ",b[j]);
			}
			printf("\n");
		}
		f(n,a,k+1,b);
		a[i]=0;
	}
	return ;
}
int main() {
	int n,a[100]={},b[100]={};
	scanf("%d",&n);
	f(n,a,1,b);
	return 0;
}
