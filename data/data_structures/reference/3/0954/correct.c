#include <stdio.h>
#include <string.h>

int main() {
	char str[500];
	char save[500];//存储小数点以外的有效数字
	gets(str);
	int flag = 0; //标记“.”的出现位置
	int e = 0; //e后面的数字
	int j = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '.')
			flag = i;
	}
	if (flag == 1) {
		if (str[0] == '0') {
			int count = 0;
			for (int i = 2; i < strlen(str); i++) {
				if (str[i] != '0') {
					break;
				} else {
					count++;
				}
			}
			e = -(count + 1);
			int judge = 0;
			for (int i = 2; i < strlen(str); i++) {
				if (str[i] != '0') {
					judge = 1;
				}
				if (judge == 1) {
					save[j++] = str[i];
				}
			}
		} else {
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] != '.') {
					save[j++] = str[i];
				}
			}
			e = 0;
		}
	} else {
		e = flag - 1;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] != '.') {
				save[j++] = str[i];
			}
		}
	}
	if (j == 1) {
		printf("%c", save[j - 1]);
		printf("e");
		printf("%d", e);
	} else {
		printf("%c", save[0]);
		printf(".");
		for (int i = 1; i < j; i++) {
			printf("%c", save[i]);
		}
		printf("e");
		printf("%d", e);
	}
	return 0;
}
