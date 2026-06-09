#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char c = ' ';
int sum = 0, num = 0, ret = 0, sign = 1, cnt = 0;

int f(int i, char ch[]) {
	int x = ch[i] - '0';
	while (ch[i + 1] >= '0' && ch[i + 1] <= '9') {
		x = x * 10 + (ch[i + 1] - '0');
		i++;
	}

	return x;
}

int main() {
	char ch[150];
	gets(ch);
	int i, j;
	for (i = j = 0; ch[i] != '\0'; i++) {
		if (ch[i] != c)
			ch[j++] = ch[i];

	}
	ch[j] = '\0';

	for (i = 0; ch[i] != '\0'; i++) {

		if (ch[i] == '+' ) {
			sum += sign * num;
			num = 0;
			ret = 0;
			sign = 1;
		} else if (ch[i] == '-') {
			sum += num * sign;
			num = 0;
			ret = 0;
			sign = -1;
		} else {
			if (ch[i] >= '0' && ch[i] <= '9') {
				if (ch[i - 1] == '+' || ch[i - 1] == '-' || i == 0) {
					num = f(i, ch);
				} else {
					if (ret == 1) {
						num /= f(i, ch);
						ret = 0;
					} else if (ret == 2) {
						num *= f(i, ch);
						ret = 0;
					}
				}
			} else if (ch[i] == '/') {
				ret = 1;
			} else if (ch[i] == '*') {
				ret = 2;
			} else if (ch[i] == '=') {
				sum += sign * num;
			}
		}
	}
	printf("%d", sum);
	return 0;
}



