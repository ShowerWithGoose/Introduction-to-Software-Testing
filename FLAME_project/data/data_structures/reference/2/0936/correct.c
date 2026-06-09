#include<stdio.h>
#include<string.h>
#include<math.h>
char s[101];
char s0[101];
void cheng(int o1, int o2, int i) {
	int a = 0, b = 0;
	for (int j = o1; j < i; j++) {
		a += (s[j] - '0') * pow(10, i - j - 1);
	}
	for (int j = i + 1; j <= o2; j++) {
		b += (s[j] - '0') * pow(10, o2 - j);
	}
	int t ;
	t = a * b;
	while (t / 10 != 0) {
		s[o2--] = (t % 10 ) + '0';
		t /= 10;
	}
	s[o2] = t + '0';
	for (int j = o1; j < o2; j++) {
		s[j] = ' ';
	}
}
void chu(int o1, int o2, int i) {
	int a = 0, b = 0;
	for (int j = o1; j < i; j++) {
		a += (s[j] - '0') * pow(10, i - j - 1);
	}
	for (int j = i + 1; j <= o2; j++) {
		b += (s[j] - '0') * pow(10, o2 - j);
	}
	int t ;
	t = a / b;
	while (t / 10 != 0) {
		s[o2--] = (t % 10 ) + '0';
		t /= 10;
	}
	s[o2] = t + '0';
	for (int j = o1; j < o2; j++) {
		s[j] = ' ';
	}
}
int jia(int temp, int os, int j) {
	int t = 0;
	for (int i = os; i <= j; i++) {
		t += (s[i] - '0') * pow(10, j - i);
	}
	return t + temp;
}
int jian(int temp, int os, int j) {
	int t = 0;
	for (int i = os; i <= j; i++) {
		t += (s[i] - '0') * pow(10, j - i);
	}
	return temp - t;
}
void chukongge(char a[], int l) {
	int j = 0;
	for (int i = 0; i < l; i++) {
		if (a[i] != ' ') {
			s0[j++] = a[i];
		}
	}
	s0[j] = '\0';
	int d = strlen(s0);
	for (int i = 0; i <= l; i++) {
		s[i] = '\0';
	}
	for (int i = 0; i <= d; i++) {
		s[i] = s0[i];
	}
}

int main() {
	gets(s);
	int l, temp = 0, o1, o2, p;
	l = strlen(s);
	chukongge(s, l);
	l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] == '*') {
			for (int j = i + 1; j < l; j++) {
				if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' || s[j] == ' ' || s[j] == '=' ) {
					o2 = j - 1;
					break;
				}
			}
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' || s[j] == ' ') {
					o1 = j + 1;
					break;
				}
			}
			cheng(o1, o2, i);
		}
		if (s[i] == '/') {
			for (int j = i + 1; j < l; j++) {
				if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' || s[j] == ' ' || s[j] == '=' ) {
					o2 = j - 1;
					break;
				}
			}
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' || s[j] == ' ' ) {
					o1 = j + 1;
					break;
				}
			}
			chu(o1, o2, i);
		}
	}
	chukongge(s, l);
	l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '=' ) {
			p = i - 1;
			break;
		}
	}
	for (int i = 0; i <= p; i++) {
		temp += (s[i] - '0') * pow(10, p - i);
	}
	for (int i = p + 1; i <= l; i++) {
		if (s[i] == '=') {
			break;
		}
		if (s[i] == '+') {
			for (int j = i + 1; j < l; j++) {
				if (s[j] == '+' || s[j] == '-' || s[j] == '=') {
					o1 = j - 1;
					break;
				}
			}
			temp = jia(temp, i + 1, o1);
		}
		if (s[i] == '-' ) {
			for (int j = i + 1; j < l; j++) {
				if (s[j] == '+' || s[j] == '-' || s[j] == '=') {
					o1 = j - 1;
					break;
				}
			}
			temp = jian(temp, i + 1, o1);
		}
	}
	printf("%d", temp);
	return 0;
}

