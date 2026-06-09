#include<stdio.h>
#include<stdlib.h>

int main() {
	char m=0,q=0;
	int n, k, t = 1, a[3][1000] = { 0 }, b[3][1000] = { 0 }, i = 1, j = 1, c[3][10000] = { 0 }, cmp;
	while (m !='\n') {
		scanf("%d%d", &a[1][i], &a[2][i]);
		i++;
		m=getchar();
	}
	n = i - 1;
	i = 1;
	while (q !='\n') {
		scanf("%d%d", &b[1][i], &b[2][i]);
		i++;
		q=getchar();
	}
	k =  (i - 1);
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= k;j++) {
			c[1][t] = a[1][i] * b[1][j];
			c[2][t] = a[2][i] + b[2][j];
			t++;
		}
	}
	n = t - 1;
	for (i = 1;i <= n;i++) {
		for (j = i + 1;j <= n;j++) {
			if (c[2][i] < c[2][j]) {
				cmp = c[2][i];
				c[2][i] = c[2][j];
				c[2][j] = cmp;
				cmp = c[1][i];
				c[1][i] = c[1][j];
				c[1][j] = cmp;
			}
			else if (c[2][i] == c[2][j]) {
				c[1][i] += c[1][j];
				c[2][j] = -1;
				c[1][j] = 0;
			}
		}
	}
	for (i = 1;i <= n && c[1][i] != 0;i++) {
		printf("%d %d ", c[1][i], c[2][i]);
	}
	return 0;
}

