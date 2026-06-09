#include <stdio.h>
#include <string.h>
#define LENGTH 105

char a[LENGTH] = {0};

char b[LENGTH] = {0};

int main() {
	int i = 0, j = 0, cnt = 0;
	gets(a);
	if (a[0] - '0' > 0) {
		while (a[i] != '.') {
			b[j++] = a[i++];
		}
		cnt = i - 1;
		i++;
		while (a[i] != '\0') {
			b[j++] = a [i++];
		}
		printf("%c.", b[0]);
		i = 1;
		while (b[i] != '\0') {
			printf("%c", b[i]);
			i++;
		}
		printf("e%d", cnt);
	} else {
		i = 2;
		while (a[i] == '0') {
			i++;
		}
		cnt = i - 1;
		while (a[i] != '\0') {
			b[j++] = a[i];
			i++;

		}
		i = 1;
		printf("%c", b[0]);
		if (b[1] != '\0') {
			printf(".");
		}
		while (b[i] != '\0') {
			printf("%c", b[i]);
			i++;
		}
		printf("e-%d", cnt);
	}
}

