#include <stdio.h>
#include <string.h>
#include <math.h>

void f(int x, int y, char s[]);

int main() {
	char s[103];
	scanf("%s", s);
	int i, j, len, hold = 0, x;
	len = strlen(s);

	if (s[0] == '-') {
		printf("-");
		if (s[1] == '0') {
			for (i = 3; i < len; i++) {
				if (s[i] >= '1' && s[i] <= '9') {
					if (i == len - 1) {
						printf("%ce-", s[i]);
					} else {
						printf("%c.", s[i]);
						f(i + 1, len, s);
						printf("-");
					}
					printf("%d", hold + 1);
				} else {
					hold++;
				}
			}
		} else {
			printf("%d.", s[1]);
			f(3, len, s);
			for (i = 1; i < len; i++) {
				if (s[i] == '.')
					hold = i;
			}
			printf("%d", hold - 2);
		}
	} else {
		if (s[0] == '0') {
			for (i = 2; i < len; i++) {
				if (s[i] >= '1' && s[i] <= '9') {
					if (i == len - 1) {
						printf("%ce-", s[i]);
					} else {
						printf("%c.", s[i]);
						f(i + 1, len, s);
						printf("-");
					}
					printf("%d", hold + 1);
				} else {
					hold++;
				}
			}
		} else {
			printf("%c.", s[0]);
			f(1, len, s);
			for (i = 1; i < len; i++) {
				if (s[i] == '.')
					hold = i;
			}
			printf("%d", hold - 1);
		}
	}
	return 0;
}

void f(int x, int y, char s[]) {
	int i = x;
	for (i; i < y; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			printf("%c", s[i]);

	}
	printf("e");
}
