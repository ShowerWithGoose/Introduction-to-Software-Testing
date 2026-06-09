#include <stdio.h>
#include <string.h>

int main(void) {
	int position = -1, len, i, j;
	char ch[10000];
	scanf("%s", ch);
	len = strlen(ch);
	for (i = 0; i < len; i++) {
		if (ch[i] == '.') {
			position = i;
			break;
		}
	}
	if (position == 1) {
		if (ch[0] == '0') {
			for (i = 2; i < len; i++) {
				if (ch[i] != '0') {
					j = i;
					break;
				}
			}
			if (j == len - 1) {
				printf("%ce-%d", ch[j], len - 2);
			} else {
				printf("%c", ch[j]);
				printf(".");
				for (i = j + 1; i < len; i++) {
					printf("%c", ch[i]);
				}
				printf("e-%d", j - 1);
			}
		} else {
			printf("%c", ch[0]);
			printf(".");
			for (i = 2; i < len; i++) {
				printf("%c", ch[i]);
			}
			printf("e0");
		}
	} else {
		printf("%c", ch[0]);
		printf(".");
		for (i = 1; i < position ; i++) {
			printf("%c", ch[i]);
		}
		for (i = position + 1; i < len; i++) {
			printf("%c", ch[i]);
		}
		printf("e%d", position - 1);
	}
	return 0;

}


