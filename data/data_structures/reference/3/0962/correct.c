#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int dot(char a[]) {
	int i = 0;
	while (a[i] != '\0') {
		if (a[i] == '.') {
			return i;
		} else {
			i++;
		}
	}
	return -1;
}

int fx(char a[]) {
	int i = strlen(a) - 1, j = 0;
	for (i; i >= 0; i--) {
		if (a[i] != '0') {
			j++;
		}
	}
	return j;
}

int f(char a[], int cnt) {
	for (int i = cnt - 1; i >= 0; i--) {
		if (a[i] != '0') {
			return i;
		}
	}
}

int y(char a[], int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (a[i] != '0' && a[i] != '.') {
			return i;
		}
	}
}

int main() {
	char ch[150];
	scanf("%s", ch);
	int i, j, begin, num, length, cnt = 0, ret = 0;
	length = strlen(ch);
	if (ch[0] != '0') {
		for (i = 0; i < length; i++) {

			if (ch[i] == '.') {
				cnt = i;
				goto end;
			}
			ret++;
		}
end:
		printf("%c", ch[0]);
		int non = f(ch, length);
		if (non != 0) {
			printf(".");
		}
		for (j = 1; j <= non; j++) {
			if (ch[j] != '.')
				printf("%c", ch[j]);
		}
		printf("e%d", ret - 1);

	} else {
		int non = y(ch, length);
		printf("%c", ch[non]);
		if (non != length - 1) {
			printf(".");
		}
		for (j = non + 1; j < length; j++) {
			if (ch[j] != '.')
				printf("%c", ch[j]);
		}
		printf("e-%d", non - 1);
	}

	/*cnt = dot(ch);
	if (cnt == -1) {
		printf("%c", ch[0]);
		if (fx(ch) != 1) {
			printf(".");
		}
		for (i = 1; i <= fx(ch); i++) {
			printf("%c", ch[i]);

		}
		printf("e%d", strlen(ch) - 1);
	}*/
	return 0;
}



