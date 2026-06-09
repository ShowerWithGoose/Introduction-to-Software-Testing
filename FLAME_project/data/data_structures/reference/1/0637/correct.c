#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int a[15];
void prt(int a[], int n);
int main(){
	int n, i, jc = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		a[i] = i; jc *= i;
	}
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)  printf(" %d", a[i]);
	printf("\n");
	for (i = 2; i <= jc; i++){
		prt(a, n);
	}
	return 0;
}

void prt(int a[], int n){
	int i = n, j, k;
	while (a[i] < a[i - 1])  i--;
	i--;
	int p = i;//最靠右的比下一个数小的下标
	int max = 20, maxn = 20;//数值和下标
	for (i = i + 1; i <= n; i++){
		if (a[i] > a[p] && a[i] < max){
			max = a[i]; maxn = i;
		}
	}
	int cmp = a[maxn];
	a[maxn] = a[p];
	a[p] = cmp;
	j = p + 1; k = n;
	while (j < k){
		cmp = a[j];
		a[j] = a[k];
		a[k] = cmp;
		j++; k--;
	}
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)  printf(" %d", a[i]);
	printf("\n");	
}


