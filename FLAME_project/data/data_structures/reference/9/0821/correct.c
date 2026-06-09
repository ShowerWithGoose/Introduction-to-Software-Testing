#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 1007
#define ll long long
ll flag[M][4],n,max=0,num=0;
typedef struct {
	ll x,y;
} Point;
Point p;
typedef struct line {
	Point node1;
	Point node2;
	int flag1;
} Line;
ll Max(ll a,ll b) {
	return a>b?a:b;
}
ll Min(ll a,ll b) {
	return a<b?a:b;
}
//int *a=(int*)malloc(n*sizeof(int)+100);
//void shellSort(int *a, int len) {
//	int i, next, k, tmp, gap;
//	for (gap = len / 2; gap > 0; gap /= 2) {
//		for (i = 0; i < gap; ++i) {
//			for (next = i + gap; next < len; next += gap) {
//				tmp = a[next];
//				k = next - gap;
//				while (k >= 0 && a[k] > tmp) {
//					a[k + gap] = a[k];
//					k -= gap;
//				}
//				a[k + gap] = tmp;
//			}
//		}
//	}
//}
int main() {
	ll i,next,k;
	scanf("%lld",&n);
	for(i=0; i<=n-1; i++) {
		scanf("%lld%lld%lld%lld",&flag[i][0],&flag[i][1],&flag[i][2],&flag[i][3]);
	}
	for(i=0; i<=n-1; i++) {
		for(next=i+1; next<=n-1; next++) {
			if(flag[i][0]>flag[next][0]) {
				for (k=0; k<4; k++) {
					ll now=flag[i][k];
					flag[i][k]=flag[next][k];
					flag[next][k]=now;
				}
			}
		}
	}
//	shellSort(flag[i],4);
	for(i=0; i<=n-1; i++) {
		ll len=i;
		num=0;
		for(next=i+1; next<=n-1; next++) {
			if(flag[len][2]==flag[next][0]&&flag[len][3]==flag[next][1]) { //x对应相等 ,y对应相等
				num++;
				len=next;
			}
		}
		if(num>max) {
			max=num;
			p.x=flag[i][0];
			p.y=flag[i][1];
		}
	}
	max++;
	printf("%lld %lld %lld",max,p.x,p.y);
	return 0;
}
//10
//80 75 125 75
//60 40 80 55
//80 55 90 20
//140 120 195 205
//10 111 70 165
//22 35 43 43
//22 175 80 205
//43 43 60 40
//90 20 125 60
//70 165 140 120


