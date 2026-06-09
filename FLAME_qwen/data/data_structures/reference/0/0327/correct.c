#include <stdio.h>
#include <string.h>

void fun(char a, char b) {
	if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b) {
		for (a++; a < b; a++)

			printf("%c", a);
		return;
	}

	if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b) {
		for (a++; a < b; a++)

			printf("%c", a);
		return;
	}

	if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && a < b) {
		for (a++; a < b; a++)

			printf("%c", a);
		return;
	}

	printf("-");
}

int main() {
	char s[10086];
	scanf("%s", s);
	printf("%c", s[0]);


	for (int i = 1; s[i] != '\0'; i++) {

		if (s[i] == '-')
			fun(s[i - 1], s[i + 1]);
		else
			printf("%c", s[i]);
	}

	return 0;
}
