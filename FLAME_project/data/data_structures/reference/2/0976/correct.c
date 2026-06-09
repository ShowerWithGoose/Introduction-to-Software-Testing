#include <stdio.h>
#include <string.h>
char s[10005];
int cal[10005], op[10005], fin[10005];

int change(int m, int n) {
	int i, ret = 0;
	for (i = m ; i <= n ; i++)
		ret = 10 * ret + (s[i] - '0');
	return ret;
}

int ishigh(int n) {
	if (s[op[n]] == '*' || s[op[n]] == '/')
		return 1;
	else
		return 0;
}

int main() {
	char c;
	int len = 0, cnt = 0, i, j = 1, cnt1 = 0, ans;
	while ((c = getchar()) != '=') {
		if (c != ' ')
			s[len++] = c;
	}

	for (i = 0; i < len; i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			op[cnt++] = i;
	}
	op[cnt] = len;
	cal[cnt1++] = change(0, op[0] - 1);
	for (i = 0; i < cnt; i++) {
		cal[cnt1++] = change(op[i] + 1, op[i + 1] - 1);
		if (s[op[i]] == '*') {
			cal[cnt1 - 2] *= cal[cnt1 - 1];
			cnt1 -= 1;
		} else if (s[op[i]] == '/') {
			cal[cnt1 - 2] /= cal[cnt1 - 1];
			cnt1 -= 1;
		}
	}
	ans = cal[0];
	for (i = 0, j = 1; i < cnt; i++) {
		if (s[op[i]] == '+')
			ans += cal[j++];
		else if (s[op[i]] == '-')
			ans -= cal[j++];
	}
	printf("%d", ans);
	return 0;
}
