#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
char ch[1000];
char plus[500];
int num[500];
int ans = 0;


int main() {
	gets(ch);
	int i, j, k = 0, t, temp = 0;

	for (i = 0, j = 0; ch[i] != '\0'; i++) {

		if (ch[i] != ' ') {
			ch[j++] = ch[i];
		}

	}

	ch[j] = '\0';
	j = 0;
	int len = strlen(ch);

	for (i = 0; i < len; i++) {

		if (isdigit(ch[i])) {
			num[j] = num[j] * 10 + (int)(ch[i] - '0');
			continue;
		}

		if (ch[i] == '+' || ch[i] == '-') {
			j++;
			plus[k] = ch[i];
			k++;
			continue;
		}

		if (ch[i] == '*' || ch[i] == '/') {

			t = i + 1;

			while (isdigit(ch[t])) {
				temp = temp * 10 + (int)(ch[t] - '0');
				t++;
			}



			if (ch[i] == '*') {
				num[j] = num[j] * temp;
			}

			if (ch[i] == '/') {
				num[j] = num[j] / temp;
			}

			temp = 0;
			i = t - 1;
			continue;
		}

		if (ch[i] == '=') {
			break;
		}
	}

	ans = num[0];
	plus[k] = '\0';


	for (i = 0; i < strlen(plus); i++) {

		if (plus[i] == '+') {
			ans += num[i + 1];
		} else if (plus[i] == '-') {
			ans -= num[i + 1];
		}
	}

	printf("%d", ans);
	return 0;
}



