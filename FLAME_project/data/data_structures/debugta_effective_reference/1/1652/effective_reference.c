#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pr printf
#define sf scanf
#define rt return
#define gcr getchar
#define pcr putchar
#define pi 3.14159265
#define sw switch
#define brk break
#define ctn continue
#define sc(x) scanf("%d",&x)
#define ef else if
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)//\n
#define max(a,b) ((a)>=(b)?(a):(b))//可修改>=or>
#define min(a,b) ((a)<=(b)?(a):(b))
#define sl strlen
#define PR printf("\n");
#define For(n) for(int i=0;i<n;++i)
#define New(p) p=(node*)malloc(sizeof(node))
#define itn int
int arr[100];
bool state[100];

void prt(int *a, int n) {
	for (int i = 1; i <= n; ++i) {
		pr("%d ", a[i]);
	}
	PR
}

void DFS(int *arr, bool *state, int n, int x) {
	if (n + 1 == x) {
		prt(arr, n);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (state[i] == 0) {
			state[i] = 1;
			arr[x] = i;
			//depth++;
			DFS(arr, state, n, x + 1);
			//每次标记一个数，depth+1
			state[i] = 0;//回溯
		} else
			ctn;
	}
}

void dfs(int *n) {
	DFS(arr, state, n, 1);
}

int main() {
	int n;
	sc(n);
	if (n == 1) {
		pr("1");
		rt 0;
	}
	if (n == 2) {
		pr("1 2\n2 1");
		rt 0;
	}
//	for (int i = 1; i < n; ++i) {
//		flag[i] = 1;
//	}
	dfs(n);
	rt 0;
}
