#include <stdio.h>
#include <string.h>

char s[200];
int step;

void readnum() {
	gets(s);
	int j = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ')
			s[j++] = s[i];
	}
	s[j] = '\0';
}

long long getnum() {
	long long result = 0;
	int num[20] = {0};
	int i = 0;
	long long t = 1;
	while (1) {
		if (s[step] >= '0' && s[step] <= '9')
			num[i++] = s[step++] - '0';
		else
			break;
	}
	for (int j = i - 1; j >= 0; j--) {
		result += num[j] * t;
		t *= 10;
	}
	return result;
}

int main() {
	readnum();
	long long sum = 0;
	long long num = 0;
	long long temp = 0;
	int flag = 1;
	int flag_1 = 0;
	num = getnum();
	while (1) {
		if (s[step] == '*') {
			flag_1 = 1;
			step++;
			temp = getnum();
			num *= temp;
		} else if (s[step] == '/') {
			flag_1 = 1;
			step++;
			temp = getnum();
			num /= temp;
		} else if (s[step] == '+') {
			flag_1 = 1;
			step++;
			if (flag == 1) {
				sum += num;
			} else
				sum -= num;
			flag = 1;
			num = getnum();
		} else if (s[step] == '-') {
			flag_1 = 1;
			step++;
			if (flag == 1) {
				sum += num;
			} else
				sum -= num;
			flag = 0;
			num = getnum();
		} else {
			if (flag == 1) {
				sum += num;
			} else
				sum -= num;
			break;
		}

	}
	printf("%lld", sum);
	return 0;
}
