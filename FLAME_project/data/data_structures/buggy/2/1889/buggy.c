#include <stdio.h>
#include <string.h>

int main() {
	int num[5] = {0};
	char pnt[5] = {'+'};
	scanf("%d %c", &num[1], &pnt[1]);
	while (pnt[1] != '=') {
		scanf("%d %c", &num[2], &pnt[2]);
		while (pnt[2] == '*' || pnt[2] == '/') {
			scanf("%d %c", &num[3], &pnt[3]);
			if (pnt[2] == '*') {
				num[2] = num[2] * num[3];
			} else if (pnt[2] == '/') {
				num[2] = num[2] / num[3];
			}
			pnt[2] = pnt[3];
		}
		if (pnt[1] == '+') {
			num[1] = num[1] + num[2];
		} else if (pnt[1] == '-') {
			num[1] = num[1] - num[2];
		}
		pnt[1] = pnt[2];
	}

	printf("%d", num[1]);
	return 0;
}
