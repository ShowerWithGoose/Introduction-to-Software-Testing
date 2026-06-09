#include <stdio.h>
#include <string.h>
char a[10000];

int pan(char a, char b) {
	if ('a' <= a && a <= 'z' && 'a' <= b && b <= 'z')
		return 1;
	if ('A' <= a && a <= 'Z' && 'A' <= b && b <= 'Z')
		return 1;
	if ('0' <= a && a <= '9' && '0' <= b && b <= '9')
		return 1;
	return 0;
}

int main(void) {
	scanf("%s", a);
	int l = strlen(a);
	for (int i = 0 ; i < l; i++) {
		if (i == l - 1 || a[i + 1] != '-') {
			if (i == 0 || a[i - 1] != '-')
				printf("%c", a[i]);
		} else {
			if (pan(a[i], a[i + 2])) {
				if (a[i - 1] != '-')
					for (char j = a[i]; j <= a[i + 2]; j++)
						printf("%c", j);
				else
					for (char j = a[i] + 1; j <= a[i + 2]; j++)
						printf("%c", j);
				i += 1;
			} else {
				printf("%c%c%c", a[i], a[i + 1], a[i + 2]);
				i += 1;
			}
		}
	}
	return 0;
}



