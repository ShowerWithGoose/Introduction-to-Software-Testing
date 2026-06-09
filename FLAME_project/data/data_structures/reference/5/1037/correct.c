#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LL long long

int RD(){
	int x=0; char ch; int f=1;
	for (; ch < '0' || ch > '9'; ch = getchar())if (f == '-') f=-1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
	return x*f;
}

typedef struct{
	int k,n; //k*x^n
	int next;
}NODE;

int cmp(const void * a, const void * b){
	NODE x = *(NODE*) a;
	NODE y = *(NODE*) b;
	return -(x.n - y.n);
}

NODE num1[1000], num2[1000], res[1000];
int cnt1,cnt2,cnt3;

int main(){
	char ch = getchar();
	int x, k, n, pre;
	x = 0;
	while (ch != '\n'){
		while (ch < '0' || ch > '9')ch = getchar();
		for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
		k = x, x = 0;
		while (ch < '0' || ch > '9')ch = getchar();
		for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
		n = x, x = 0;
		num1[cnt1].k = k;
		num1[cnt1++].n = n;
	}
	x = 0, ch = getchar();
	while (ch != '\n'){
		while (ch < '0' || ch > '9')ch = getchar();
		for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
		k = x, x = 0;
		while (ch < '0' || ch > '9')ch = getchar();
		for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
		n = x, x = 0;
		num2[cnt2].k = k;
		num2[cnt2++].n = n;
	}
	for (int i = 0; i < cnt1; i++){
		for (int j = 0; j < cnt2; j++){
			k = num1[i].k * num2[j].k;
			n = num1[i].n + num2[j].n;
			int good = 0;
			for (int p = 0; p < cnt3; p++){
				if (res[p].n == n){
					res[p].k += k;
					good = 1;
					break;
				}
			}
			if (good == 0){
				res[cnt3].k = k;
				res[cnt3++].n = n;
			}
		}
	}
	qsort(res, cnt3, sizeof(res[0]), cmp);
	for (int p = 0; p < cnt3; p++){
		printf("%d %d ", res[p].k, res[p].n);
	}
	return 0;
}
