#include<stdio.h>
#include <math.h>
#include<string.h>
#define MAXN 10
int sum[MAXN];
char num[11];
int x;
void re(int m) {
	int i;
	if (m == x) {
		for (i = 0; i < x; i++) {
			printf("%d%c", num[i], " \n"[i == x - 1]);
		}
		return;
	}
	for (i = 1; i <= x; i++)
		if (sum[i] == 0) {
			sum[i] = 1;
			num[m] = i;
			re(m + 1);
			sum[i] = 0;
		}
}
int main() {
	scanf("%d", &x);
	re(0);
	return 0;
}

