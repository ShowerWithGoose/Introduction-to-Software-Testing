#include <stdio.h>

int main() {
	int flag = 0;
	long long num[200] = {0};
	char sym[200] = {0};
	int p = 0;
	long long n;
	char c;
	do {
		scanf("%lld", &n);
		do {
			c = getchar();
		} while (c == ' ');
		num[p] = n;
		sym[p] = c;
		p++;
	} while (c != '=');
	do {
		flag = 0;
		int t = 0;
		while (sym[t] != '*' && sym[t] != '/' && sym[t] != '\0') {
			t++;
		}
		if (sym[t] != '\0') {
			flag = 1;
			if (sym[t] == '*') {
				num[t + 1] *= num[t];
			} else if (sym[t] == '/') {
				num[t + 1] = num[t] / num[t + 1];
			}
			while (sym[t] != '\0') {
				num[t] = num[t + 1];
				sym[t] = sym[t + 1];
				t++;
			}
		}
	} while (flag != 0);
	int t = 0;
	while (sym[t] != '=') {
		if (sym[t] == '+') {
			num[t + 1] = num[t] + num[t + 1];
		} else if (sym[t] == '-') {
			num[t + 1] = num[t] - num[t + 1];
		}
		t++;
	}
	printf("%lld", num[t]);
}


