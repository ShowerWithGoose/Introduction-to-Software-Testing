#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[10086] = "";
	int index[10086] = { -1 };
	scanf("%s", s);
	for (int i = 0, j = 0; i < strlen(s); i++) {
		if (s[i] == '-') {
			if ((('a' <= s[i - 1] && s[i - 1] <= 'z') && ('a' <= s[i + 1] && s[i + 1] <= 'z')) || (('A' <= s[i - 1] && s[i - 1] <= 'Z') && ('A' <= s[i + 1] && s[i + 1] <= 'Z')) || (('0' <= s[i - 1] && s[i - 1] <= '9') && ('0' <= s[i + 1] && s[i + 1] <= '9'))) {
				index[j++] = i;
			}
		}
	}
	for (int i = 0, j = 0; i < strlen(s); i++) {
		if (i != index[j]) printf("%c", s[i]);
		else {
			if (s[i - 1] < s[i + 1]) {
				for (int st = s[i - 1] + 1, fn = s[i + 1]; st < fn; st++) {
					printf("%c", st);
				}
			}
			else printf("-");
			j++;
		}
	}
	return 0;
}
