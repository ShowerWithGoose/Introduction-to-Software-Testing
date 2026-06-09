#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 11
int mark[MAX] = {0},a[MAX],n;
void rank(int m) {
	if(m==n){
		for(int i=0;i<n;i++) {
			printf("%d ",a[i]);
		}
		printf("\n");
		return; 
	}
	for(int i=0;i<n;i++) {
		if(mark[i]==0) {
			a[m]=i+1;
			mark[i]=1;
			rank(m+1);
			mark[i]=0;
		}
	}
}
 
int main() {
	scanf("%d",&n);
	rank(0);
	return 0;
}

