#include <stdio.h>
#include <string.h>
char flo[105];

int main() {
	int i, l, flag, j;
	gets(flo);
	l = strlen(flo);
	for (i = 0; i < l; i++) {
		if (flo[i] == '.')
			flag = i;
	}
	if (flag > 1) {
		printf("%c.", flo[0]);
		for (i = 1; i < l; i++) {
			if (flo[i] != '.')
				printf("%c", flo[i]);
		}
		printf("e%d", flag - 1);
	} else {
		if (flo[0] != '0') {
			for (i = 0; i < l; i++)
				printf("%c", flo[i]);
			printf("e0");
		} else {
			for (i = flag + 1; i < l; i++) {
				if (flo[i] != '0')
					break;
			}
			printf("%c", flo[i]);
			if (i != l - 1) {
				printf(".");
				for (j = i + 1; j < l; j++)
					printf("%c", flo[j]);
			}
			printf("e%d", flag - i);
		}
	}
	return 0;
}
