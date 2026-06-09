#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main() {
	char s[100000];
	int count = 0, j, r, i, ji = 0;
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != '-') {
			printf("%c", s[i]);
		} else  {
			if (('a' <= s[i - 1] && s[i + 1] <= 'z') || ('A' <= s[i - 1] && s[i + 1] <= 'Z') || ('0' <= s[i - 1] && s[i + 1] <= '9')) {
				j = s[i + 1] - s[i - 1];
				for (int r = 1; r < j; r++) {
					printf("%c", s[i - 1] + r);
				}
			} else printf("%c", s[i]);
		}
	}

	return 0;
}

