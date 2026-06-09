#include <stdio.h>
#include <string.h>
#include <math.h>
char c[100000];
int a[100000];
char b[100000];

int main() {
	int i = 0, j = 0, k = 0, q = 0;
	int sum = 0;
	int len;
	int flag;
	gets(c);
	for (i = 0; c[i] != '\0'; i++) {
		if (47 < c[i] && c[i] < 58) {
			for (q = 0; 47 < c[i + q] && c[i + q] < 58; ) {
				q++;
			}
			q--;
			for (q ; q >= 0; q--) {
				a[k] += (c[i] - 48 ) * pow(10, q);
				i++;
				if (q == 0) {
					k++;
					i--;
				}
			}
		}
	}
	for (i = 0; c[i] != '\0'; i++) {
		if (c[i] == '+' || c[i] == '=' || c[i] == '-' || c[i] == '*' || c[i] == '/')
			b[j++] = c[i];
	}
	len = strlen(b);
//	for (i = 0; i < len; i++) {
//		printf("%c ", b[i]);
//		printf("%d ", a[i]);
//	}
	k = 0;
	for (i = 0; b[i] != '\0'; i++) {
		if (b[i] == '*') {
			a[i + 1] = a[i] * a[i + 1];
			a[i] = 0;
		}
		if (b[i] == '/') {
			a[i + 1] = a[i] / a[i + 1];
			a[i] = 0;
		}
	}

	for (i = 0; i < len; i++) {
		if (a[i] != 0) {
			sum = a[i];
			flag = i;
			break;
		}
	}
	for (i = flag; b[i] != '\0'; i++) {
		if (b[i] == '+') {
			for (k = i + 1; k < len; k++) {
				if (a[k] != 0) {
					sum += a[k];
					break;
				}
			}
		}
		if (b[i] == '-') {
			for (k = i + 1; k < len; k++) {
				if (a[k] != 0) {
					sum -= a[k];
					break;
				}
			}
		}
	}
	printf("%d", sum);

//1+2*3*4+8/6/3
//b[]=+ * * +  / / =
//a[]=1 0 0 24 0 0 0
	return 0;
}

