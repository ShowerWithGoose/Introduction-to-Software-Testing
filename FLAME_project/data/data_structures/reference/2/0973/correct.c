#include <stdio.h>
#include <string.h>

int main() {
	char s1[100] = {}, s2[100] = {}, s3[100] = {};
	gets(s1);
	int i2 = 0, sum1 = 0, sum2 = 0, x = 0;
	for (int i1 = 0; i1 < strlen(s1); i1++) {
		if (s1[i1] == ' ')
			continue;
		s2[i2++] = s1[i1];
	}
	int sign1 = 0, sign2 = 0, sign0 = 0, flag = 0, ori = 0;
	for (int i = 0; i < strlen(s2); i++) {
		if (flag == 0) {
			for (int p = i; p < strlen(s2); p++) {
				if (s2[p] == '+' || s2[p] == '-' || s2[p] == '*' || s2[p] == '/' || s2[p] == '=') {
					ori = p;
					break;
				}
			}
			for (int k = i; k < ori; k++ ) {
				sum2 = 10 * sum2 + s2[k] - '0';
			}
			flag = 1;
		}
		if (s2[i] == '=') {
			if (s2[sign1] == '+')
				sum1 += sum2;
			else if (s2[sign1] == '-')
				sum1 -= sum2;
			else
				sum1 = sum2;
		}
		if (s2[i] == '+' || s2[i] == '-') {
			sign0 = sign1;
			sign1 = i;
			if (s2[sign0] == '+')
				sum1 += sum2;
			else if (s2[sign0] == '-')
				sum1 -= sum2;
			else
				sum1 = sum2;
			sum2 = 0;
			flag = 0;
		}
		if (s2[i] == '*') {
			for (int k1 = i + 1; k1 < strlen(s2); k1++) {
				if (s2[k1] == '+' || s2[k1] == '-' || s2[k1] == '*' || s2[k1] == '/' || s2[k1] == '=') {

					sign2 = k1;
					break;
				}
			}
			for (int k = i + 1; k < sign2; k++) {
				x = 10 * x + s2[k] - '0';
			}
			sum2 = sum2 * x;
			x = 0;
		}
		if (s2[i] == '/') {
			for (int k1 = i + 1; k1 < strlen(s2); k1++) {
				if (s2[k1] == '+' || s2[k1] == '-' || s2[k1] == '*' || s2[k1] == '/' || s2[k1] == '=') {

					sign2 = k1;
					break;
				}
			}
			for (int k = i + 1; k < sign2; k++) {
				x = 10 * x + s2[k] - '0';
			}
			sum2 = sum2 / x;
			x = 0;
		}
	}
	printf("%d", sum1);
	return 0;
}
