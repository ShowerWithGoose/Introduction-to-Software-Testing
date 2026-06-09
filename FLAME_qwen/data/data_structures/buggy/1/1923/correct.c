#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))

void perm(int a[], int p, int q);
void swap1(int a[], int i, int p);
void swap2(int a[], int i, int p);
int main()
{
	int n, i;
	int a[100];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		a[i]=i+1;
	}
	perm(a, 0, n-1);
	return 0;
}

void perm(int a[], int p, int q){//p前面，q后面 
	int i, len;
	if(p==q){
		len=q+1;
		for(i=0; i<len; i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	else{
		for(i=p; i<=q; i++){
			swap1(a, i, p);
			perm(a, p+1, q);//递归 
			swap2(a, i, p);
		}
	}
}

void swap1(int a[], int i, int p){//后移 
	int temp, re;
	temp=a[i];
	re=i;
	for(i=re; i>p; i--){
		a[i]=a[i-1];
	}
	a[p]=temp;
}

void swap2(int a[], int i, int p){//前移 
	int temp, re;
	temp=a[p];
	re=i;
	for(i=p+1; i<=re; i++){
		a[i-1]=a[i];
	}
	a[re]=temp;
}

