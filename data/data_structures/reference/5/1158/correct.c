#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char x[999], y[999];
int a[999], b[999], c[999], d[999], e[999], f[999], i, r, j, k, n, m, t, s, l, su, p, q;

int main( ) {
	n = 1;
	m = 1;
	x[0] = ' ';
	y[0] = ' ';
	gets(x + 1);
	gets(y + 1);
	p = strlen(x + 1);
	q = strlen(y + 1);
	x[p + 1] = ' ';
	y[q + 1] = ' ';
	for (i = 0; i <= p; i++) {
		if (x[i] == ' ') {
			for (j = i + 1; j <= p + 1; j++) {
				if (x[j] == ' ') {
					if (r == 0) {
						for (k = j - 1; k > i; k--) {
							a[n] = a[n] + (x[k] - '0') * pow(10, j - k - 1);
						}
						n++;
						r++;
					} else if (r == 1) {
						for (k = j - 1; k > i; k--) {
							b[m] = b[m] + (x[k] - '0') * pow(10, j - k - 1);
						}
						m++;
						r--;
					}
					break;
				}
			}
		}
	}
	l = n - 1;
	r = 0;
	n = 1;
	m = 1;
	for (i = 0; i <= q; i++) {
		if (y[i] == ' ') {
			for (j = i + 1; j <= q + 1; j++) {
				if (y[j] == ' ') {
					if (r == 0) {
						for (k = j - 1; k > i; k--) {
							c[n] = c[n] + (y[k] - '0') * pow(10, j - k - 1);
						}
						n++;
						r++;
					} else if (r == 1) {
						for (k = j - 1; k > i; k--) {
							d[m] = d[m] + (y[k] - '0') * pow(10, j - k - 1);
						}
						m++;
						r--;
					}
					break;
				}
			}
		}
	}
	s = n - 1;
	k = 1;
	for (i = 1; i <= l; i++) {
		for (j = 1; j <= s; j++) {
			f[k] = b[i] + d[j];
			e[k] = a[i] * c[j];
			k++;
		}
	}
	k--;
	for (i = 1; i <= k; i++) {
		for (j = 1; j <= k - i; j++) {
			if (f[j + 1] > f[j]) {
				t = f[j + 1];
				f[j + 1] = f[j];
				f[j] = t;
				t = e[j + 1];
				e[j + 1] = e[j];
				e[j] = t;
			}
		}
	}
	t = 1;
	for (i = 1; i <= k; i++) {
		if (i == k) {
			printf("%d %d ", e[i], f[i]);
		} else {
			if (f[i] > f[i + t]) {
				printf("%d %d ", e[i], f[i]);
				goto B;
			}
A:
			if (f[i] == f[i + t]) {
				t++;
				goto A;
			} else if (f[i] > f[i + t]) {
				for (j = i; j <= i + t - 1; j++) {
					su = su + e[j];
				}
				if (su != 0) {
					printf("%d %d ", su, f[i]);
				}
				i = i + t - 1;
				t = 1;
				su = 0;
			}
B:
			t = 1;
		}
	}
	return 0;
}

