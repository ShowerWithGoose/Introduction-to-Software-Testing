#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int num[120], cnt = 0, length, i = 0, j, n, m;
	scanf("%d", &n);
	while (n != -1) {
		if (n == 1) {
			scanf("%d", &m);
			cnt++;
			if (cnt > 100) {
				printf("error ");
			}
			num[cnt] = m;
		} else if (n == 0) {
			cnt--;
			if (cnt < 0) {
				printf("error ");
				cnt = 0;
			} else {
				printf("%d ", num[cnt + 1]);
			}

		}
		scanf("%d", &n);
	}


	return 0;
}

