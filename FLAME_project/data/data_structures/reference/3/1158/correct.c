#include <stdio.h>
#include <string.h>
#include <math.h>

char a[111], b[111];
int i, j, k, n, m, h;

int main() {
	gets(a + 1);
	n = strlen(a + 1);
	for (i = 1; i <= n; i++) {
		if (a[i] == '.') {
			k = i;
			break;
		}
	}
	for (i = 1; i <= n; i++) {
		if (a[i] != '0' && a[i] != '.') {
			b[1] = a[i];
			m = i;
			if (i == n) {
				printf("%ce%d", b[1], 2 - n);
				break;
			} else if (a[1] == '0') {
				b[2] = '.';
				h = 3;
				for (j = i + 1; j <= n; j++) {
					if (a[j] != '.') {
						b[h] = a[j];
						h++;
					}
				}
				b[h] = 'e';
				for (j = 1; j <= h; j++) {
					printf("%c", b[j]);
				}
				printf("%d", 2 - m);
				break;
			} else if (a[1] != '0') {
				b[2] = '.';
				h = 3;
				for (j = i + 1; j <= n; j++) {
					if (a[j] != '.') {
						b[h] = a[j];
						h++;
					}
				}
				b[h] = 'e';
				for (j = 1; j <= h; j++) {
					printf("%c", b[j]);
				}
				printf("%d", k - 2);
				break;
			}
		}
	}
}
