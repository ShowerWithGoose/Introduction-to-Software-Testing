#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1024

char s[MAXLEN], t[MAXLEN];

int main() {
	int num, i, j, count;
	scanf("%s", s);
	for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
		if (s[i] != '-') 
			t[j] = s[i];
		else if (i && (num = s[i + 1] - s[i - 1]) > 0) {
			if (islower(s[i - 1]) && islower(s[i + 1])) {
				count = 0;
				while (--num) {
					count++;
					t[j++] = s[i - 1] + count;
				}
				j--;
			}
			else if (isupper(s[i - 1]) && isupper(s[i + 1])) {
				count = 0;
				while (--num) {
					count++;
					t[j++] = s[i - 1] + count;
				}
				j--;
			}
			else if (isdigit(s[i - 1]) && isdigit(s[i + 1])) {
				count = 0;
				while (--num) {
					count++;
					t[j++] = s[i - 1] + count;
				}
				j--;
			}
			else t[j] = s[i];
		}
	}
	t[j] = '\0';
	printf("%s\n", t);
	return 0;
}

