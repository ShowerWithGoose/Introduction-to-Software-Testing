#include <stdio.h>
#include <string.h>

int main() {
	char st[100];
	gets(st);
	if (st[1] == '.') {
		if (st[0] == '0') {
			int count = 0;
			int i;
			for ( i = 2; st[i] == '0'; i++) {
				count++;
			}
			printf("%c", st[i]);
			if (i + 1 < strlen(st)) {
				printf(".");
			}
			for (i = i + 1; i < strlen(st); i++) {
				printf("%c", st[i]);
			}
			printf("e-%d", count + 1);
		} else if (st[0] != '0') {
			printf("%se0", st);
		}
	} else {
		int place = 0;
		for (int j = 0; j < strlen(st); j++) {
			if (st[j] == '.') {
				place = j;
			}
		}
		if (place == 0) {
			place = strlen(st);
		}
		printf("%c.", st[0]);
		for (int p = 1; p < strlen(st); p++) {
			if (st[p] != '.') {
				printf("%c", st[p]);
			}
		}
		printf("e%d", place - 1);
	}
}
