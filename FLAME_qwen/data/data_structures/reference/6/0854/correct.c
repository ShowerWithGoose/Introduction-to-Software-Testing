#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
int main() {
	int a, b[100], c[100], flag[100] = {0};
	int t;
	int i = 0, j = 0;
	while (scanf("%d", &a) != EOF) {
		if (a == 1) {
			scanf("%d", &t);
			b[i++] = t;
		}
		if (a == 0) {
			if (i == 0||i==100) {
				flag[j++] = 1;
			}
			if (i != 0) {
				c[j++] = b[--i];
			}
		}
		if (a == -1) {
			break;
		}
	}
	for (i = 0; i < j; i++) {
		if (flag[i] == 1) {
			printf("error ");
		} else {
			printf("%d ", c[i]);
		}
	}

}

