/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2024-02-27 22:28
    说明:

*********************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char a[100001], fuhao[10001];
int b[10001], c[10001], num[10001], d[10001];
int f(char a, int b, int c) {
	switch (a) {
		case '+':
			return b + c;
		case '-':
			return b - c;
		case '*':
			return b * c;
		case '/':
			return b / c;
	}
}

int main() {
	gets(a);
	int i, j;
	for (i = j = 0; a[i] != '\0'; i++)
		if (a[i] != ' ')
			a[j++] = a[i];
	a[j] = '\0';
	int m = 0, n = 0, p = 1, f1 = 0;
	for (int x = 0; x < j; x++) {
		if (a[x] == '+' || a[x] == '-') {
			m++;
			p++;
			f1++;
			b[m] = f1;
			fuhao[f1] = a[x];

		} else if (a[x] == '*' || a[x] == '/') {
			n++;
			p++;
			f1++;
			c[n] = f1;
			fuhao[f1] = a[x];

		} else if (a[x] == '=')
			break;
		else
			num[p] = num[p] * 10 + a[x] - '0';
	}

	for (int x = 1; x <= n; x++) {
		num[c[x]] = f(fuhao[c[x]], num[c[x]], num[c[x] + 1]);
		num[c[x] + 1] = num[c[x]];
		int l = c[x];
		while (l > 0) {
			if (fuhao[l - 1] == '*' || fuhao[l - 1] == '/') {

				num[l - 1] = num[l];
				l = l - 1;
			} else
				break;
		}
	}
	int sum = num[1];
	for (int x = 1; x <= m; x++) {
		sum = f(fuhao[b[x]], sum, num[b[x] + 1]);
	}
	printf("%d", sum);
	return 0;
}
