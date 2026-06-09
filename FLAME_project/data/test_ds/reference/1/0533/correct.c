#include <stdio.h>
#include <stdlib.h>

int judge(char a, char b) {
	if (a <= 'z' && a >= 'a' && b <= 'z' && b >= 'a')
		return 1;
	else if (a <= 'Z' && a >= 'A' && b <= 'Z' && b >= 'A')
		return 1;
	else if (a <= '9' && a >= '0' && b <= '9' && b >= '0')
		return 1;
	else
		return 0;
}

int main(void) {
	int i, j, l = 0, r = 0;
	char in[100000] = "", out[100000] = "";
	gets(in);
	for (i = 0; in[i] != 0; i++) {
		if (in[i] == '-') {
			if ( judge(in[i - 1], in[i + 1]) ) {
				for (int x = in[i - 1] + 1; x <= in[i + 1] - 1; x++)
					printf("%c", x);
			} else {
				printf("-");
			}
		} else
			printf("%c", in[i]);
	}

	return 0;
}



