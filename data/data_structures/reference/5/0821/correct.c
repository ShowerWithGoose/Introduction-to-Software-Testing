#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define ll long long
//int a[M];
int Max(int a,int b) {
	return a>b?a:b;
}
int Min(int a,int b) {
	return a<b?a:b;
}
//int *a=(int*)malloc(n*sizeof(int)+100);
typedef struct {
	ll x;
	ll value;
} Node;
Node a[M],b[M],flag[M];
//int flag[M];
char s[M],ch[M];
ll value[M];
void shellSort(Node *a, int len) {
	int i, j, k, gap;
	Node tmp;
	for (gap = len / 2; gap > 0; gap /= 2) {
		for (i = 0; i < gap; ++i) {
			for (j = i + gap; j < len; j += gap) {
				tmp = a[j];
				k = j - gap;
				while (k >= 0 && a[k].x < tmp.x) {
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = tmp;
			}
		}
	}
}
int main() {
	int i=0,num=0,j,k,n,m;
	char c;
	while(1) {
		scanf("%lld %lld%c",&a[i].value,&a[i].x,&c);
		if(c=='\n') {
			break;
		}
		i++;
	}
//	scanf("%d",&m);
	n=i;
	i=0;
	while(1) {
		scanf("%lld %lld%c",&b[i].value,&b[i].x,&c);
		if(c=='\n') {
			break;
		}
		i++;
	}
	m=i;
//	for(i=0; i<m; i++) {
//		scanf("%d %d",&b[i].value,&b[i].x);
//	}
	for(i=0; i<=n; i++) {
		for(j=0; j<=m; j++) {
			int flag1=1;	
			for(k=0; k<num; k++) {
				if(flag[k].x==(a[i].x+b[j].x)) {
					flag1=0;
					flag[k].value+=a[i].value*b[j].value;
				}
			}
			if(flag1==1) {
				flag[num].x=a[i].x+b[j].x;
				flag[num++].value+=a[i].value*b[j].value;
			}
		}
	}
	i=0;
	shellSort(flag,num);
	for(j=flag[0].x;j=flag[i].x, i<num; i++) {
		printf("%lld %lld ",flag[i].value,j);
	}
	return 0;
}



