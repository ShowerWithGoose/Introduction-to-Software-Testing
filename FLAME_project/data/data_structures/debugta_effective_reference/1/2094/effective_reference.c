#include<stdio.h>
#include<stdlib.h>
void swap(int[],int,int);
void func(int[],int);
int rise(const void*p1,const void*p2){
	if(*(int*)p1<*(int*)p2) return -1;
	if(*(int*)p1>*(int*)p2) return 1;
	return 0;
}
void swap(int a[],int m,int n){
	int temp;
	temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}

int main(){
	int n,a[100];
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		a[k]=k+1;
		printf("%d ",a[k]);
	}
	printf("\n");
	func(a,n);
}
void func(int a[],int n){
	int x,y;
	for(int k=n-1;k>0;k--){
		if(a[k-1]<a[k]){
			x=k-1;
			for(int j=n-1;j>x;j--){
				if(a[j]>a[x]){
					y=j;
					swap(a,x,y);
					qsort((int*)a+x+1,n-x-1,4,rise);
					for(int k=0;k<n;k++){
						printf("%d ",a[k]);
					}
					printf("\n");
					func(a,n);
				}
			}
		}
	}
} 


