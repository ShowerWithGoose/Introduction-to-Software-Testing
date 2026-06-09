#include <stdio.h>
#include <string.h>
char judge[10000];

char expand(char ch[]) {
	int i;
	char j;
	for (i = 0; i < strlen(ch); i++) {
		if (ch[i] == '-') {
			if (ch[i - 1] < ch[i + 1]) {
				if (ch[i - 1] >= 'a' && ch[i - 1] <= 'z' && ch[i + 1] >= 'a' && ch[i + 1] <= 'z') {
					for (j = ch[i - 1] + 1; j < ch[i + 1]; j++)
						printf("%c", j);
				} else if (ch[i - 1] >= 'A' && ch[i - 1] <= 'Z' && ch[i + 1] >= 'A' && ch[i + 1] <= 'Z') {
					for (j = ch[i - 1] + 1; j < ch[i + 1]; j++)
						printf("%c", j);

				} else if (ch[i - 1] >= '0' && ch[i - 1] <= '9' && ch[i + 1] >= '0' && ch[i + 1] <= '9') {
					for (j = ch[i - 1] + 1; j < ch[i + 1]; j++)
						printf("%c", j);
				} else {
					printf("%c", ch[i]);
				}
			}

		} else {
			printf("%c", ch[i]);
		}

	}
	return 0;
}

int main(void) {
	char ch[10000];
	scanf("%s", ch);
	expand(ch);
	return 0;
}


