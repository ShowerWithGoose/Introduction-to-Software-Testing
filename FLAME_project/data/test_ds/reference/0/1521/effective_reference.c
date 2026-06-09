#include <stdio.h>
#include <string.h>
char fm[100000], b[100], c[100000];
int main() {
	scanf("%s", fm);
	for (int i = 0; i < strlen(fm); i++) {
		if (fm[i] == '-') {
			if (fm[i - 1] < fm[i + 1] && (('a' <= fm[i - 1] && fm[i + 1] <= 'z') || ('A' <= fm[i - 1] && fm[i + 1] <= 'Z') || ('0' <= fm[i - 1] && fm[i + 1] <= '9'))) {
			
				strcpy(c, &fm[i + 1]);
				c[strlen(fm) - (i + 1)] = '\0';
				int j;
				for (j = 0; j < (fm[i + 1] - fm[i - 1]); j++) {
					b[j] = fm[i - 1] + j;
			}
				b[j] = '\0';
				fm[i - 1] = '\0';
				strcat(fm, b);
				strcat(fm, c);
				i--;
			}
		}
	}
	printf("%s", fm);
	return 0;
}

