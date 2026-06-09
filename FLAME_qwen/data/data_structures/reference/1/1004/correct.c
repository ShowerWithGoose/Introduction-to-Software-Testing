#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int a[11],b[11],c[11];
int full(int k,int n){
	int j,m;
	if(k==n){
		for(m=0;m<n;m++)
			printf("%d ",b[m]);
		printf("\n");
	}
	else{
		for(j=0;j<n;j++){
			if(c[j]==0){
				b[k]=a[j];
				c[j]=1;
				full(k+1,n);
				c[j]=0;
			}
		}
	}
}
int main(){
	int n,i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=i+1;
	k=0;
	full(k,n);
return 0;
}




