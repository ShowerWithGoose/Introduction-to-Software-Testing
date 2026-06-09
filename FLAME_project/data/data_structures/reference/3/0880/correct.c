#include <stdio.h>
#include <ctype.h>
#include <string.h>

int func_e(char s[]) { //计算e后的数字
	int a = 0;
	if (s[0] == '0') {
		for (int m = 2; s[m] == '0'; m++)
			a++;
		return -(a + 1);
	} else {
		for (int m = 1; s[m] != '.' && s[m] != '\0'; m++)
			a++;
		return a;
	}
}

int main() {
	char s[105];
	int i = 0, e, len;
	scanf("%s", s);
	len = strlen(s);
	if (len == 1)
		printf("%ce0", s[0]);
	else {
		for (i = 0; s[i] == '0' || s[i] == '.'; i++) ;
		printf("%c", s[i]);
		i += 1;
		if (isdigit(s[i]) || isdigit(s[i + 1]))
			printf(".");
		for (; s[i] != '\0'; i++)
			if (isdigit(s[i]))
				printf("%c", s[i]);
		e = func_e(s);
		printf("e%d", e);
	}
	return 0;
}
