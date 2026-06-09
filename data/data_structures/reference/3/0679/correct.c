#include <stdio.h>
#include <string.h>
char s[105];

int main() {
	int flag = 0;
	gets(s);
	if (s[0] == '0') {
		int i = 2;
		for (i = 2; s[i] == '0'; i++) {
			flag++;
		}
		printf("%c", s[i]);
		if (s[i + 1] != '\0')
			printf(".");
		for (i += 1; i < strlen(s); i++)
			printf("%c", s[i]);
		printf("e-%d", flag + 1);
	}

	else {
		int flag0 = 0;
		for (int f = 0; s[f] != '.'; f++) {
			flag0++;
		}
		printf("%c.", s[0]);
		for (int f = 1; f < strlen(s); f++)
			if (s[f] != '.')
				printf("%c", s[f]);
		printf("e%d", flag0 - 1);
	}
	return 0;
}
