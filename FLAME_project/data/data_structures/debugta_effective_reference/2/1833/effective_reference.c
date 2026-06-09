#include <stdio.h>
#include <string.h>
#include <math.h>
char a[1001], b[9999], d[5555];
int h, i, j, k, n, m, s, sum;
int c[9999], f[9999];

int main() {
	for (i = 1; i <= 9998; i++) {
		f[i] = 1;
	}
	gets(a + 1);
	n = strlen(a + 1);
	j = 1;
	for (i = 1; i <= n; i++) {
		if (a[i] != ' ') {
			b[j] = a[i];
			j++;
		}
	}/*É¾¿Õ¸ñ*/
	n = strlen(b + 1);
	h = 2;
	m = 1;
	for (i = 2; i <= n; i++) {
		if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/' || b[i] == '=') {
			for (k = 1; k < i; k++) {
				c[1] = c[1] + (b[k] - '0') * (pow(10,  i - k - 1));
			}
			break;
		}
	}
	for (i = i; i <= n; i++) {
		if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/' || b[i] == '=') {
			d[m] = b[i];
			m++;
			for (j = i + 1; j <= n; j++) {
				if (b[j] == '+' || b[j] == '-' || b[j] == '*' || b[j] == '/' || b[j] == '=') {
					s = j - i - 1;
					for (k = 1; k <= s; k++) {
						c[h] = c[h] + (b[i + k] - '0') * (pow(10, s - k));
					}
					h++;
					break;
				}
			}
		}
	}
	h = 1;
	for (i = 1; i <= m - 1; i++) {
		if (d[i] == '+' || d[i] == '-' || d[i] == '=') {
			if (i == 1) {
				f[h] = c[i];
				break;
			} else {
				f[h] = c[1];
				for (k = 1; k < i; k++) {
					if (d[k] == '*') {
						f[h] = f[h] * c[k + 1];
					} else if (d[k] == '/') {
						f[h] = f[h] / c[k + 1];
					}
				}
				break;
			}
		}
	}
	h = 2;
	for (i = 1; i <= m - 1; i++) {
		if (d[i] == '+' || d[i] == '-' || d[i] == '=') {
			for (j = i + 1; j <= m - 1; j++) {
				if (d[j] == '+' || d[j] == '-' || d[j] == '=') {
					f[h] = c[i + 1];
					for (k = 1; k < j - i; k++) {
						if (d[i + k] == '*')
							f[h] = f[h] * c[i + k + 1];
						else if (d[i + k] == '/')
							f[h] = f[h] / c[i + k + 1];
					}
					h++;
					break;
				}
			}
		}
	}
	sum = f[1];
	j = 2;
	for (i = 1; i <= m - 1; i++) {
		if (d[i] == '+') {
			sum = sum + f[j];
			j++;
		} else if (d[i] == '-') {
			sum = sum - f[j];
			j++;
		}
	}
	printf("%d", sum);
	return 0;
}
