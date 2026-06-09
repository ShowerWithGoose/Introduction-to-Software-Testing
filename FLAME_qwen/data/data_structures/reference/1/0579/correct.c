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
	for(int i=0;i<n;i++){
		a[i]=i+1;
		printf("%d ",a[i]);
	}
	printf("\n");
	func(a,n);
}
void func(int a[],int n){
	int x,y;
	for(int i=n-1;i>0;i--){
		if(a[i-1]<a[i]){
			x=i-1;
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


