#include<stdio.h>
#include<string.h>
char s[100];
int judge(char a, char b) {
	if (a < b && a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
		return 1;
	else if (a < b && a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
		return 1;
	else if (a < b && a >= '0' && a <= '9' && b >= '0' && b <= '9')
		return 1;
	else return 0;
}
int main() {
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i <= len - 1; ) {
		if (s[i] != '-') {
			printf("%c", s[i]);
			i++;
		} else {
			if (judge(s[i - 1], s[i + 1])) {
				for (int j = s[i - 1] + 1; j <= s[i + 1]; j++) {
					printf("%c", j);
				}
				i += 2;
			} else {
				printf("%c", s[i]);
				i++;
			}
		}
	}
	return 0;
}



