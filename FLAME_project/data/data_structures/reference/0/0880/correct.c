#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define num (isdigit(s[i-1])&&isdigit(s[i+1])&&s[i+1]>s[i-1])
#define alp (islower(s[i-1])&&islower(s[i+1])&&s[i+1]>s[i-1])

#define lalp (isupper(s[i-1])&&isupper(s[i+1])&&s[i+1]>s[i-1])//宏定义判断前后是否合法
void largeput(char s[], int len) { //扩展输出
	int n;
	printf("%c", s[0]);
	for (int i = 1; i < len - 1; i++) {
		if (s[i] == '-' && (num || alp || lalp)) {
			n = s[i + 1] - s[i - 1] - 1;
			while (n--) {
				printf("%c", s[i + 1] - n - 1);
			}
		} else
			printf("%c", s[i]);
	}
	printf("%c", s[len - 1]);
}

int main() {
	char s[100];
	scanf("%s", s);
	int len = strlen(s);
	largeput(s, len);
	return 0;
}
