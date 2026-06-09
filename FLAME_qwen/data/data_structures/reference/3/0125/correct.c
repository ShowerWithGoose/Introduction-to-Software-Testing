#include <stdio.h>
#include <string.h>

char str[1000];
int i = 0, k = 0;

int main() {
	scanf("%s", str);
	if (str[1] == '.') {
		if (str[0] == '0') {
			for (i = 2; str[i] == '0'; i++);
			k = i - 1;
			if (k == strlen(str) - 2) {
				printf("%c", str[i]);
				printf("e-%d", k);
			} else {
				printf("%c.", str[i++]);
				for (; str[i] != '\0'; i++) {
					printf("%c", str[i]);
				}
				printf("e-%d", k);
			}
		} else {
			for (i = 0; str[i] != '\0'; i++) {
				printf("%c", str[i]);
			}
			printf("e0");
		}
	} else {
		for (i = 0; str[i] != '.'; i++);
		k = i - 1;
		printf("%c.", str[0]);
		for (i = 1; str[i] != '\0'; i++) {
			if (str[i] == '.') {
				continue;
			} else
				printf("%c", str[i]);
		}
		printf("e%d", k);
	}
	return 0;
}
