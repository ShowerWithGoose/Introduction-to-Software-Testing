#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
char s[100010];
char n[100010];
char op[1000];
int num[1000];
int ans = 0;
int main() {
	gets(s);

	for (int i = 0, j = 0; i < strlen(s); i++) { //去除空格
		if (s[i] == ' ') continue;
		n[j++] = s[i];
	}
	int numdigit = 0;
	//读入数字和运算符
	for (int i = 0, j = 0, hash = 0; i < strlen(n); i++) {
		if (n[i] == '=') break;
		if (n[i] == '+' || n[i] == '-' || n[i] == '*' || n[i] == '/') {
			op[j++] = n[i];
			hash = 0;
			numdigit++;
		} else if (hash == 0) {
			num[numdigit] = n[i] - '0';
			hash = 1;
		} else
			num[numdigit] = num[numdigit] * 10 + n[i] - '0';

	}

	//运算，先算乘法。
	for (int i = 0; i < strlen(op); i++) {
		if (op[i] == '*') { //乘法
			num[i + 1] *= num[i];
		} else if (op[i] == '/') { //除法
			num[i + 1] = num[i] / num[i + 1];
		}
		continue;
	}

	int hashop = 0; //＋为0，减为1；
	for (int i = 0; i < strlen(op); i++) {
		if (op[i] == '+') {

			if (hashop == 0) {
				ans += num[i];
			} else ans -= num[i];

			hashop = 0;
		} else if (op[i] == '-') {
			if (hashop == 0) {
				ans += num[i];
			} else ans -= num[i];

			hashop = 1;

		} else continue;

	}
	if (hashop == 0) {
		ans += num[numdigit];
	} else ans -= num[numdigit];

	printf("%d", ans);

	return 0;
}

