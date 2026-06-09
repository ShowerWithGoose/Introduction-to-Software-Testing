#include <stdio.h>

int main() {
	char in[120];
	gets(in);
	int t = 0;
	while (in[t] == '0') {
		t++;
	}
	if (in[t] == '.') {
		//负指数
		t++;
		int e = 0;
		while (in[t] == '0')
			e--, t++;
		putchar(in[t]);
		if (in[t + 1] != '\0')
			putchar('.');
		t++;
		while (in[t] != '\0')
			putchar(in[t++]);
		printf("e%d", e - 1);
	} else {
		//正指数
		int e = 0;
		int start = t;
		int end = 0;
		while (in[t] != '.') {
			t++, e++;
		}
		t = start;
		putchar(in[t]);
		putchar('.');
		t++;
		while (in[t] != '\0') {
			if (in[t] != '.')
				putchar(in[t++]);
			else
				t++;
		}
		printf("e%d", e - 1);
	}
}
