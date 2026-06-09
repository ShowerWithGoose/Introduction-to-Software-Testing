#include <stdio.h>
#include <string.h>

int main() {
	char s[105] = {};
	gets(s);
	int flag = 0, pos = 0, p1 = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '.') {
			flag = 1;
			pos = i;
		}
	}
	if (flag == 1) {
		if (pos == 1) {
			if (s[0] > '0') {
				printf("%d%c", s[0] - '0', s[1]);
				for (int k = 2; k < strlen(s); k++)
					printf("%d", s[k] - '0');
				printf("e0");
				return 0;
			} else {
				for (int k = 0; k < strlen(s); k++) {
					if (s[k] > '0' && s[k] <= '9') {
						p1 = k;
						break;
					}
				}
				if (p1 == strlen(s) - 1) {
					printf("%de-%d", s[p1] - '0', p1 - pos);
					return 0;
				} else {
					printf("%d.", s[p1] - '0');
					for (int k = p1 + 1; k < strlen(s); k++) {
						printf("%d", s[k] - '0');
					}
					printf("e-%d", p1 - 1);
					return 0;
				}
			}
		} else {
			printf("%d.", s[0] - '0');
			for (int k = 1; k < pos; k++) {
				printf("%d", s[k] - '0');
			}
			for (int k = pos + 1; k < strlen(s); k++) {
				printf("%d", s[k] - '0');
			}
			printf("e%d", pos - 1);
			return 0;
		}
	} else {
		for (int k = 1; k < strlen(s); k++) {
			if (s[k] > '0' && s[k] <= '9') {
				p1 = k;
			}
		}
		if (p1 == 0) {
			printf("%de%d", s[0] - '0', strlen(s) - 1);
			return 0;
		} else {
			printf("%d.", s[0] - '0');
			for (int k = 1; k <= p1; k++) {
				printf("%d", s[k] - '0');
			}
			printf("e%d", strlen(s) - 1);
			return 0;
		}
	}
}
