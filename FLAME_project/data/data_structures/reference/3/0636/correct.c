#include<stdio.h>
#include<string.h>
int main() {
	char s[110];
	int dot, e, i = 0, inti, flag = 1;
	gets(s);
	if (s[0] == '0') {
		while ((s[i] == '0') || (s[i] == '.')) {
			if (s[i] == '.') //可以处理.前有多个0的情况
				dot = i;
			i++;
		}
		inti = i;
		e = dot - i;
		if (s[++i] == '\0')
			flag = 0;
	} else {
		inti = 0;
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == '.')
				dot = i;
		}
		e = dot - 1;
	}
	printf("%c", s[inti]);
	if (flag)
		printf(".");
	for (i = inti + 1; s[i] != '\0'; i++)
		if (s[i] != '.')
			printf("%c", s[i]);
	printf("e%d", e);
	return 0;
}



