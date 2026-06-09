#include <stdio.h>
#include <string.h>

int main() {
	char a[10000];
	gets(a);
	int l = strlen(a);
	for (int i = 0; i < l; i++) {
		if (a[i] == '-') {
			if ((a[i - 1] >= 'a' && a[i + 1] <= 'z') ||
			        (a[i - 1] >= 'A' && a[i + 1] <= 'Z') ||
			        (a[i - 1] >= '0' && a[i + 1] <= '9')) {
				int j = a[i - 1], k = a[i + 1];
				for (int q = j + 1; q < k; q++) {
					printf("%c", q);
				}
			} else {
				printf("%c", a[i]);
			}
		} else {
			printf("%c", a[i]);
		}
	}
	return 0;
}
