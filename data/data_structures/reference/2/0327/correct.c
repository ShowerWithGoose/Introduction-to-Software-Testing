#include <stdio.h>
#include <string.h>

int main() {
	char c, s[1000];
	int a = 0, block[200] = {0}, flag = 0, number[500] = {0}, cnt = 0, i = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			s[i] = c;
			i++;
		}
	}

	s[i] = '\0';

	for (int j = 0; s[j] != '\0'; j++) {

		if (s[j] >= '0' && s[j] <= '9') {
			if (flag == 1)
				a = a * 10 + s[j] - '0';
			else {
				flag = 1;
				a = s[j] - '0';
			}
		} else {
			number[cnt] = a;
			cnt++;
			flag = 0;
		}
	}

	cnt = 0;
	flag = 0;
	int cnnt = 0;

	for (int j = 0; s[j] != '\0'; j++) {

		if (s[j] == '*') {
			if (flag == 0) {
				block[cnt] = number[cnnt];
				cnnt++;
				block[cnt] *= number[cnnt];
				cnnt++;
				flag = 1;
				continue;
			}

			if (flag == 1) {
				block[cnt] *= number[cnnt];
				cnnt++;
			}
		}

		if (s[j] == '/') {
			if (flag == 0) {
				block[cnt] = number[cnnt];
				cnnt++;
				block[cnt] = block[cnt] / number[cnnt];
				cnnt++;
				flag = 1;
				continue;
			}

			if (flag == 1) {
				block[cnt] /= number[cnnt];
				cnnt++;
			}
		}

		if (s[j] == '+' || s[j] == '-' || s[j] == '=') {
			if (flag == 0) {
				block[cnt] = number[cnnt];
				cnnt++;
				cnt++;
			}

			if (flag == 1) {
				cnt++;
				flag = 0;
			}
		}
	}

	cnt = 1;
	a = block[0];

	for (int j = 0; s[j] != '\0'; j++) {

		if (s[j] == '+') {
			a += block[cnt];
			cnt++;
		}

		if (s[j] == '-') {
			a -= block[cnt];
			cnt++;
		}
	}

	printf("%d\n", a);
	return 0;
}
