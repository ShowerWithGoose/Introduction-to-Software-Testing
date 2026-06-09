#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char ch[150];
	scanf("%s", ch);
	int i, j;
	for (i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == '-') {
			if (ch[i - 1] >= 'a' && ch[i - 1] <= 'z' && ch[i + 1] >= 'a' && ch[i + 1] <= 'z' && ch[i + 1] > ch[i - 1]) {
				for (j = ch[i - 1] + 1; j < ch[i + 1]; j++) {
					printf("%c", j);
				}
			} else if (ch[i - 1] >= '0' && ch[i - 1] <= '9' && ch[i + 1] >= '0' && ch[i + 1] <= '9' && ch[i + 1] > ch[i - 1]) {
				for (j = ch[i - 1] + 1; j < ch[i + 1]; j++) {
					printf("%c", j);
				}
			} else if (ch[i - 1] >= 'A' && ch[i - 1] <= 'Z' && ch[i + 1] >= 'A' && ch[i + 1] <= 'Z' && ch[i + 1] > ch[i - 1]) {
				for (j = ch[i - 1] + 1; j < ch[i + 1]; j++) {
					printf("%c", j);
				}
			} else {
				printf("-");
			}

		} else {
			printf("%c", ch[i]);
		}
	}

	return 0;
}



