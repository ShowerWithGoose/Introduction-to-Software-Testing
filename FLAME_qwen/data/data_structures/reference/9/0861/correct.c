#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
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
#define fsf fscanf
#define fpr fprintf

typedef struct node {
	int x1, x2, y1, y2;
} node;

void sort(node *L, int n) {
	node t;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (L[i].x1 > L[j].x1) {
				t = L[i];
				L[i] = L[j];
				L[j] = t;
			}
		}
	}
}
node L[200];

int main() {
	int N;
	sc(N);
	for (int i = 0; i < N; ++i) {
		sf("%d %d %d %d", &L[i].x1, &L[i].y1, &L[i].x2, &L[i].y2);
	}
	sort(L, N);
//	PR
//	for (int i = 0; i < N; ++i) {
//		pr("%d %d %d %d\n", L[i].x1, L[i].y1, L[i].x2, L[i].y2);
//	}
	int max = 0;
	int maxx = 0, maxy = 0;
	for (int i = 0; i < N; ++i) {
		int cnt = 1;
		//用右端点找左端点
		int xL = L[i].x2;
		itn yL = L[i].y2;
		for (int j = i + 1; j < N; ++j) {
//			if(L[j].x2==L[i].x1 && L[j].y2==L[i].y1){
//				cnt++;
//			}
			if (xL == L[j].x1 && yL == L[j].y1) {
				xL = L[j].x2;
				yL = L[j].y2;
				//xL yL得以保存但是j++
				cnt++;
			}
		}
		if (cnt > max) {
			max = cnt;
			maxx = L[i].x1;
			maxy = L[i].y1;
		}

	}
	pr("%d %d %d", max, maxx, maxy);
}
