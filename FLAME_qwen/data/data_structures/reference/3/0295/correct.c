#include <stdio.h>
#include <string.h>
char ord[100];
char sci[100];
int main() {

	gets(ord);
	int len = strlen(ord);
	int i;
	int cnt = 0;

	if (ord[0] != '0') {
		int back = len;
		for (i = 0; i < len; i++ ) {
			if (ord[i] != '.') {
				cnt++;
			} else break;
		}
		for (i = len - 1; i >= 0; i-- ) {
			if (ord[i] == '0') {
				back--;
			} else break;
		}
		//printf("%d\n",back);
		printf("%c", ord[0]);
		if (back != 1) {
			printf(".");
		}
		for (i = 1; i < back; i++) {
			if (ord[i] == '.')
				continue;
			printf("%c", ord[i]);

		}

		printf("e%d", cnt - 1);
	} else {
		for (i = 2; i < len; i++) {
			if (ord[i] == '0') {
				cnt++;
			} else break;
		}

		printf("%c", ord[cnt + 2]);
		if (cnt + 2 != len - 1) {
			printf(".");
		}
		for (i = cnt + 3; i < len; i++) {
			printf("%c", ord[i]);
		}

		printf("e-%d", cnt + 1);

	}
	return 0;
}

