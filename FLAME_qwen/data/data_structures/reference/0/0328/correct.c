#include <stdio.h>
#include <string.h>

int main() {
	char c[2000];
	gets(c);
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] != '-')
			printf("%c", c[i]);
		else if (c[i - 1] >= '0' && c[i + 1] <= '9' && c[i + 1] >= '0' && c[i + 1] <= '9' && c[i + 1] > c[i - 1]) {
			for (int j = c[i - 1] + 1; j < c[i + 1]; j++) {
				printf("%c", j);
			}
		} else if (c[i - 1] >= 'a' && c[i + 1] <= 'z' && c[i + 1] >= 'a' && c[i + 1] <= 'z' && c[i + 1] > c[i - 1]) {
			for (int j = c[i - 1] + 1; j < c[i + 1]; j++) {
				printf("%c", j);
			}
		} else if (c[i - 1] >= 'A' && c[i + 1] <= 'Z' && c[i + 1] >= 'A' && c[i + 1] <= 'Z' && c[i + 1] > c[i - 1]) {
			for (int j = c[i - 1] + 1; j < c[i + 1]; j++) {
				printf("%c", j);
			}
		} else
			printf("-");
	}
	return 0;
}
