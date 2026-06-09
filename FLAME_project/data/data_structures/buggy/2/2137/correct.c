#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *blank(char []);
int getnum(char[], int, int);
int pwr(int a, int b);

int main() {
	char str[1000];
	char sym[500];
	int num[500];
	int flag = 0, first = 0;
	gets(str);
	strcpy(str, blank(str));
//fine
	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] < '0' || str[i] > '9') ) {
			sym[flag] = str[i];
			flag++;
		}
	}
	//get symbol
	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] == '*') || (str[i] == '/')) {
			first++;
		}
	}
	//get first calculated symbol
	int k = 0, t = 0;
	for (int j = 0; j < strlen(str); j++) {
		if (str[j] < '0' || str[j] > '9') {
			num[t] = getnum(str, k, j);
			t++;
			k = j;//change here
		}

	}
	//get number
	while (first > 0) {
		for (int i = 0; i < strlen(sym); i++) {
			if ((sym[i] == '*')) {
				num[i] *= num[i + 1];
				for (int m = i + 1; m < t - 1; m++) {
					num[m] = num[m + 1];
				}
				t--;
				for (int m = i; m < flag - 1; m++) {
					sym[m] = sym[m + 1];
				}
				first--;
				flag--;
				i--;
			}
			if ((sym[i] == '/')) {
				num[i] /= num[i + 1];
				for (int m = i + 1; m < t - 1; m++) {
					num[m] = num[m + 1];
				}
				t--;
				for (int m = i; m < flag - 1; m++) {
					sym[m] = sym[m + 1];
				}

				first--;
				flag--;
				i--;
			}
		}
	}
	while (flag > 1) {

		int number_counter = 0;
		for (int i = 0; i < flag - 1; i++) {
			if ((sym[0] == '+')) {
				num[0] += num[1];
				for (int m = 1; m < t - 1; m++) {
					num[m] = num[m + 1];
				}
				t--;
				for (int m = 0; m < flag - 1; m++) {
					sym[m] = sym[m + 1];
				}

				flag--;
			} else if ((sym[0] == '-')) {
				num[0] -= num[1];
				for (int m = 1; m < t - 1; m++) {
					num[m] = num[m + 1];
				}
				t--;
				for (int m = 0; m < flag - 1; m++) {
					sym[m] = sym[m + 1];
				}

				flag--;
			}

		}
	}
	printf("%d", num[0]);

	return 0;
}


char *blank(char s[]) {
	char *newStr;
	int i, j = 0;

	newStr = (char *)malloc(strlen(s) + 1);
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') {
			newStr[j++] = s[i];
		}
	}
	newStr[j] = '\0';

	return newStr;
}

int getnum(char s[], int p, int q) {

	int w, sum = 0;
	if (p == 0) {
		w = q;
		for (int i = 0; i < w; i++)
			sum += (s[q - 1 - i] - '0' ) * pwr(10, i);
	} else {
		w = q - p - 1;
		for (int i = 0; i < w; i++)
			sum += (s[q - 1 - i] - '0' ) * pwr(10, i);
	}
	return sum;
}

int pwr(int a, int b) {
	int ans = 1;
	while (b) {
		ans *= a;
		b--;
	}
	return ans;
}

