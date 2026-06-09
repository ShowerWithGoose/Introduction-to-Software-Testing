#include <stdio.h>
#include <string.h>

int main() {
	int i = 0, len, m, l = 0, r, k;
	char str[1000];
	gets(str);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == '-') {
			if (str[i - 1] >= '0' && str[i - 1] <= '9' && str[i + 1] >= '0' && str[i + 1] <= '9' && (str[i + 1] - str[i - 1]) > 0) {
				r = i - 1;
				for (k = l; k <= r; k++)
					printf("%c", str[k]);
				for (m = 1; m < str[i + 1] - str[i - 1]; m++) {
					printf("%c", str[i - 1] + m);
				}
				l = i + 1;
			} else if (str[i - 1] >= 'a' && str[i - 1] <= 'z' && str[i + 1] >= 'a' && str[i + 1] <= 'z'
			           && (str[i + 1] - str[i - 1]) > 0) {
				r = i - 1;
				for (k = l; k <= r; k++)
					printf("%c", str[k]);
				for (m = 1; m < str[i + 1] - str[i - 1]; m++) {
					printf("%c", str[i - 1] + m);
				}
				l = i + 1;
			} else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z' && str[i + 1] >= 'A' && str[i + 1] <= 'Z'
			           && (str[i + 1] - str[i - 1]) > 0) {
				r = i - 1;
				for (k = l; k <= r; k++)
					printf("%c", str[k]);
				for (m = 1; m < str[i + 1] - str[i - 1]; m++) {
					printf("%c", str[i - 1] + m);
				}
				l = i + 1;
			} else
				continue;
		}
	}
	for (i = l; i < len; i++) {
		printf("%c", str[i]);
	}

	return 0;


}


