#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s[10000];
	scanf("%s", s);
	for (int i = 0; i <= strlen(s) - 1; i++) {
		if (s[i] == '-') {
			if (islower(s[i - 1]) && islower(s[i + 1])) {
				for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
					printf("%c", j);
			} else if (isupper(s[i - 1]) && isupper(s[i + 1])) {
				for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
					printf("%c", j);
			} else if (isdigit(s[i - 1]) && isdigit(s[i + 1])) {
				for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
					printf("%c", j);
			} else {
				printf("-");
			}

		} else {
			printf("%c", s[i]);
		}
	}
	return 0;
}

