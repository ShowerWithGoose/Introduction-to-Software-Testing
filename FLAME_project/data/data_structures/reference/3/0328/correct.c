#include <stdio.h>
#include <string.h>

int main() {
	char str[100 + 10];
	gets(str);
	int flag = 0;
	int flag_f = 0;
	int flag_0 = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '-')
			flag_f = 1;
		else if (str[i] == '0' && flag == 0) {
			flag_0 = 1;
		} else if (str[i] != '0' && str[i] != '.') {
			flag = 1;
		}
	}
	if (flag_0 == 1 && flag_f == 0) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] != '0' && str[i] != '.') {
				printf("%c", str[i]);
				for (int j = i + 1; str[j] != '\0'; j++) {
					if (j == i + 1)
						printf(".");
					printf("%c", str[j]);
				}
				printf("e-%d", i - 1);
				break;
			}
		}
	}
	if (flag_0 == 1 && flag_f == 1) {
		printf("-");
		for (int i = 1; str[i] != '\0'; i++) {
			if (str[i] != '0' && str[i] != '.') {
				printf("%c", str[i]);
				for (int j = i + 1; str[j] != '\0'; j++) {
					if (j == i + 1)
						printf(".");
					printf("%c", str[j]);
				}
				printf("e-%d", i - 2);
				break;
			}
		}
	}
	if (flag_0 == 0 && flag_f == 0) {
		int e = 0;
		printf("%c.", str[0]);
		for (int i = 1; str[i] != '\0'; i++) {
			if (str[i] == '.') {
				e = i - 1;
				continue;
			}
			printf("%c", str[i]);
		}
		printf("e%d", e);
	}
	if (flag_0 == 0 && flag_f == 1) {
		int e = 0;
		printf("-%c.", str[0]);
		for (int i = 2; str[i] != '\0'; i++) {
			if (str[i] == '.') {
				e = i - 2;
				continue;
			}
			printf("%c", str[i]);
		}
		printf("e%d", e);
	}
	return 0;
}
