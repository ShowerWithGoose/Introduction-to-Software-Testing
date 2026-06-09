#include <stdio.h>
#include <string.h>

int main() {
	char a[1000], fh[1000];
	int sz[1000] = {0}, amt = 0; //k用于记录数字的个数
	gets(a);
	int l = strlen(a);
	for (int k = 0; k < l; k++) {
		if (a[k] >= '0' && a[k] <= '9') {
			sz[amt] = sz[amt] * 10 + a[k] - 48;
		} else if (a[k] == '+' || a[k] == '-' ||
		           a[k] == '*' || a[k] == '/') {
			fh[amt] = a[k];
			amt++;
		}
	}
	for (int k = 0; k < amt; k++) {
		if (fh[k] == '*') {
			sz[k + 1] = sz[k] * sz[k + 1];
			sz[k] = 0;
		}
		if (fh[k] == '/') {
			sz[k + 1] = sz[k] / sz[k + 1];
			sz[k] = 0;
		}
	}
	for (int k = 0; k < amt; k++) {
		if (fh[k] == '+') {
			int xs = sz[k];
			while (sz[k + 1] == 0)
				k++;
			sz[k + 1] = xs + sz[k + 1];
		} else if (fh[k] == '-') {
			int xs = sz[k];
			while (sz[k + 1] == 0)
				k++;
			sz[k + 1] = xs - sz[k + 1];
		}
	}
	printf("%d", sz[amt]);
	return 0;
}
