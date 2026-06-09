#include <stdio.h>

int main() {
	char ysf[10000];
	int num[10000];
	int ans = 0;
	ysf[0] = '+';
	while (ysf[0] != '=') {
		scanf("%d %c", &num[1], &ysf[1]);
		while (ysf[1] == '*' || ysf[1] == '/') {
			scanf("%d %c", &num[2], &ysf[2]);
			if (ysf[1] == '*') {
				num[1] *= num[2];
			}
			if (ysf[1] == '/') {
				num[1] /= num[2];
			}
			ysf[1] = ysf[2];
		}
		if (ysf[0] == '+') {
			ans += num[1];
		}
		if (ysf[0] == '-') {
			ans -= num[1];
		}
		ysf[0] = ysf[1];

	}
	printf("%d", ans);
	return 0;
}


