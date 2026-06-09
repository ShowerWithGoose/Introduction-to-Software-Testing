#include <stdio.h>
#include <string.h>
char ch[1000];
char temp1, temp2;

int main() {
	gets(ch);
	int str = strlen(ch);

	for (int i = 0; i < str; i++) {

		if (ch[i] != '-') {
			printf("%c", ch[i]);
			temp1 = ch[i];
		} else if (ch[i] == '-') {
			temp2 = ch[i + 1];

			if (i == 0) {
				printf("%c", ch[i]);
			} else {
				if (temp1 <= '9' && temp1 >= '0') {
					if (temp2 <= '9' && temp2 >= '0' && temp2 > temp1) {
						temp1++;

						for (; temp1 < temp2; temp1++) {

							printf("%c", temp1);
						}
					} else {
						printf("-");
					}
				} else if (temp1 <= 'Z' && temp1 >= 'A') {
					if (temp2 <= 'Z' && temp2 >= 'A' && temp2 > temp1) {
						temp1++;

						for (; temp1 < temp2; temp1++) {

							printf("%c", temp1);
						}
					} else {
						printf("-");
					}
				} else if (temp1 <= 'z' && temp1 >= 'a') {
					if (temp2 <= 'z' && temp2 >= 'a' && temp2 > temp1) {
						temp1++;

						for (; temp1 < temp2; temp1++) {

							printf("%c", temp1);
						}
					} else {
						printf("-");
					}
				}
			}
		}
	}

	return 0;
}



