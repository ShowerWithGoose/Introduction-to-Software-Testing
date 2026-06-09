#include<stdio.h>
#include<ctype.h>//字符类型判断
#include<string.h>//字符串处理
#include<stdlib.h>//qsort,rand,bsearch,
int main() {
	char ch[1005],sh;
	int i=1;
	scanf("%s", ch);
	printf("%c", ch[0]);
	sh=ch[strlen(ch)-1];
	for (int i = 1; i < strlen(ch) - 1; i++) {
		if (ch[i] == '-') {
			if (ch[i - 1] >= 'a' && ch[i - 1] <= 'z' && ch[i + 1] >= 'a' && ch[i + 1] <= 'z' && ch[i - 1] < ch[i + 1]) {
				for (int j = 1; j < (ch[i + 1] - ch[i - 1]); j++) {
					printf("%c", ch[i - 1] + j);
				}
			}
			else if (ch[i - 1] >= 'A' && ch[i - 1] <= 'Z' && ch[i + 1] >= 'A' && ch[i + 1] <= 'Z' && ch[i - 1] < ch[i + 1]) {
				for (int j = 1; j < (ch[i + 1] - ch[i - 1]); j++) {
					printf("%c", ch[i - 1] + j);
				}
			}
			else if (ch[i - 1] >= '0' && ch[i - 1] <= '9' && ch[i + 1] >= '0' && ch[i + 1] <= '9' && ch[i - 1] < ch[i + 1]) {
				for (int j = 1; j < (ch[i + 1] - ch[i - 1]); j++) {
					printf("%c", ch[i - 1] + j);
				}
			}else {
				printf("-");
			}
		} else {
			printf("%c", ch[i]);
		}
	}
	printf("%c", sh);
	return 0;
}

