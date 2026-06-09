#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int i, j, k, n, t, m, X, Y, len[111];
int xx1[111], yy1[111], xx2[111], yy2[111];


int main( ) {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &xx1[i], &yy1[i], &xx2[i], &yy2[i]);
	}
	for (i = 1; i <= n; i++) {
		len[i] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {
			if (xx1[j] > xx1[j + 1]) {
				t = xx1[j];
				xx1[j] = xx1[j + 1];
				xx1[j + 1] = t;
				t = xx2[j];
				xx2[j] = xx2[j + 1];
				xx2[j + 1] = t;
				t = yy1[j];
				yy1[j] = yy1[j + 1];
				yy1[j + 1] = t;
				t = yy2[j];
				yy2[j] = yy2[j + 1];
				yy2[j + 1] = t;
			}
		}
	}
	m = len[1];
	for (i = 1; i <= n - 1; i++) {
		X = xx2[i];
		Y = yy2[i];
		for (j = i + 1; j <= n; j++) {
			if (X == xx1[j] && Y == yy1[j]) {
				len[i]++;
				X = xx2[j];
				Y = yy2[j];
			}
		}
		if (len[i] > m) {
			m = len[i];
			k = i;
		}
	}
	printf("%d %d %d", m, xx1[k], yy1[k]);
	return 0;
}

