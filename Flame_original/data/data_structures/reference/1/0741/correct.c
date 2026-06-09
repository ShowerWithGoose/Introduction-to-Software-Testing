#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000000
#define ll long long

void swap(int a[],int i,int j){
	int temp=a[j],k;
	for(k=j;k>i;k--){
		a[k]=a[k-1];
	}
	a[i]=temp;
}

void reswap(int a[],int i,int j){
	int temp=a[i],k;
	for(k=i;k<j;k++){
		a[k]=a[k+1];
	}
	a[j]=temp;
}

void perm(int a[],int i,int j){
	if(i==j){
		for(int z=0;z<=j;z++){
			printf("%d ",a[z]);
		}
		printf("\n");
	}else{
		int k;
		for(k=i;k<=j;k++){
			swap(a,i,k);

			// for(int w=0;w<=j;w++){
			// 	printf("%d ",a[w]);
			// }
			// printf("\n");

			perm(a,i+1,j);
			reswap(a,i,k);
			
			// for(int k=0;k<=j;k++){
			// 	printf("%d ",a[k]);
			// }
			// printf("\n");

		}
	}
}

int main() {
	int a[10]={1,2,3,4,5,6,7,8,9,10},n;
	scanf("%d",&n);
	perm(a,0,n-1);
	
	return 0;
}


