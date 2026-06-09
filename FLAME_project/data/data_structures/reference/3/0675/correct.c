#include <stdio.h>
#include <string.h>

int main() {
	char a[1000];
	gets(a);
	int l = strlen(a);
	if (a[1] == '.' && a[0] > '0') {
		for (int i = 0; i < l; i++) {
			printf("%c", a[i]);
		}
		printf("e0");
	} else if (a[1] == '.') {
		int i = 0;
		for (i = 2; i < l; i++) {
			if (a[i] > '0' && a[i] <= '9')
				break;
		}
		if (i < l - 1)
			printf("%c.", a[i]);
		else
			printf("%c", a[i]);
		for (int j = i + 1; j < strlen(a); j++) {
			printf("%c", a[j]);
		}
		printf("e-%d", i - 1);
	} else {
		int i = 0;
		for (i = 2; i < l; i++) {
			if (a[i] == '.')
				break;
		}
		printf("%c.", a[0]);
		for (int j = 1; j < i; j++) {
			printf("%c", a[j]);
		}
		for (int j = i + 1; j < l; j++) {
			printf("%c", a[j]);
		}
		printf("e%d", i - 1);
	}
	return 0;
}
