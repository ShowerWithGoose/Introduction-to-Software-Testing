#include <stdio.h>

char s[110];
int main() {
	gets(s);
	int i = 0, j;
	while (s[i] != '\0') {
		if (s[i] == '-') {
			if (s[i - 1] >= 'a' && s[i + 1] >= s[i - 1] && s[i + 1] <= 'z') {
				for (j = s[i - 1] + 1; j < s[i + 1]; j++) {
					printf("%c", j);
				}
			} else if (s[i - 1] >= 'A' && s[i + 1] >= s[i - 1] && s[i + 1] <= 'Z') {
				for (j = s[i - 1] + 1; j < s[i + 1]; j++) {
					printf("%c", j);
				}
			} else if (s[i - 1] >= '0' && s[i + 1] >= s[i - 1] && s[i + 1] <= '9') {
				for (j = s[i - 1]+ 1; j < s[i + 1]; j++) {
					printf("%c", j);
				}
			} else {
				printf("-");
			}
			i++;
		} else {
			printf("%c", s[i++]);
		}
	}
	return 0;
}

/*
要求：只处理[a-z]、[A-Z]、[0-9]范围内的字符扩展，即只有当扩展符前后的字符同时是小写字母、大写字母或数字，
并且扩展符后的字符大于扩展符前的字符时才进行扩展，其它情况不进行扩展，原样输出。
例如：a-R、D-e、0-b、4-B等字符串都不进行扩展。
 */

