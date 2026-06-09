#include <stdio.h>
#include <string.h>

char a[1002], b[9999];
int i, j, k, n;

int main() {
	gets(a + 1);
	n = strlen(a + 1);
	j = 1;
	for (i = 1; i <= n; i++) {
		if (a[i] != '-') {
			b[j] = a[i];
			j++;
		} else if (a[i] == '-') {
			if (((a[i - 1] >= 'a' && a[i - 1] <= 'z') && (a[i + 1] >= 'a' && a[i + 1] <= 'z')) || ((a[i - 1] >= '0'
			        && a[i - 1] <= '9') && (a[i + 1] >= '0' && a[i + 1] <= '9')) || ((a[i - 1] >= 'A' && a[i - 1] <= 'Z')
			                && (a[i + 1] >= 'A' && a[i + 1] <= 'Z'))) {
				for (k = 1; k <= (a[i + 1] - a[i - 1] - 1); k++) {
					b[j] = a[i - 1] + k;
					j++;
				}
			} else {
				b[j] = a[i];
				j++;
			}
		}
	}
	puts(b + 1);
	return 0;
}
