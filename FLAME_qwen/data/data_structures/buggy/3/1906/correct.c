#include <stdio.h>
#include <string.h>

int main() {
	char a[110] = {'\0'};
	gets(a);
	int N = strlen(a);
	if (a[0] == '0' && N != 1) {
		int i = 2;
		while (a[i] == '0') {
			i = i + 1;
		}
		int j = i;
		if ((N - j) != 1)
			printf("%c.", a[i]);
		else
			printf("%c", a[i]);
		i++;
		for (i; i <= N - 1; i++) {
			printf("%c", a[i]);
		}
		printf("e-%d", j - 1);
	} else {
		int temp = 0;
		for (int j = 0; j <= N - 1; j++) {
			if (a[j] == '.') {
				temp = 1;
				break;
			}
		}
		if (temp == 0 && N == 1) {
			printf("%ce0", a[0]);
		} else if (temp == 0 && N != 1) {
			printf("%c.", a[0]);
			for (int s = 2; s <= N - 1; s++) {
				printf("%c", a[s]);
			}
			printf("e%d", N - 1);
		} else {
			int M;
			printf("%c.", a[0]);
			for (int t = 1; t <= N - 1; t++) {
				if (a[t] != '.') {
					printf("%c", a[t]);
				} else {
					M = t;
				}
			}
			printf("e%d", M - 1);
		}
	}
	return 0;
}
