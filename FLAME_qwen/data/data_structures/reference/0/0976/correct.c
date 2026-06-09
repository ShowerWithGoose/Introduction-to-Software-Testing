#include <stdio.h>
#include <string.h>
char s[10005], ch[10005];

int main() {
	int i, j, len = 0, m;
	char c = '\0';
	gets(s);
	for (i = 0; i <= strlen(s) ; i++) {
		if (s[i] != '-') {
			printf("%c", s[i]);
		} else {
			if (((s[i - 1] >= 'A' && s[i - 1] <= 'Z') && (s[i + 1] >= s[i - 1]) && (s[i + 1] >= 'A' && s[i + 1] <= 'Z'))
			        || ((s[i - 1] >= 'a' && s[i - 1] <= 'z') && (s[i + 1] >= s[i - 1]) && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
			        || ((s[i - 1] >= '0' && s[i - 1] <= '9') && (s[i + 1] >= s[i - 1]) && (s[i + 1] >= '0' && s[i + 1] <= '9')) ) {
				for (c = s[i - 1] + 1; c < s[i + 1]; c++)
					printf("%c", c);
			} else
				printf("-");
		}
	}
	return 0;
}
