#include <stdio.h>
#include <string.h>
char ch[100];

int main() {
	gets(ch);
	int str = strlen(ch), i;

	for (i = 0; ch[i] != '.' && ch[i] != '\0'; i++)

		;

	if (i == str) {
		printf("%c.", ch[0]);

		for (int j = 1; j < str; j++) {

			printf("%c", ch[j]);
		}

		printf("e%d", str - 1);
	} else {
		if (ch[0] != '0') {
			printf("%c.", ch[0]);


			for (int j = 1; j < str ; j++) {

				if (ch[j] != '.')
					printf("%c", ch[j]);
			}

			printf("e%d", i - 1);
		} else if (ch[0] == '0') {
			int k;

			for (k = 0;; k++) {

				if (ch[k] <= '9' && ch[k] >= '1') {
					break;
				}
			}

			int temp = k + 1;
			printf("%c", ch[k]);

			if (temp < str) {
				printf(".");
			}

			k++;

			for (; k < str; k++) {

				printf("%c", ch[k]);
			}

			printf("e-%d", temp - 2);
		}
	}

	return 0;
}



