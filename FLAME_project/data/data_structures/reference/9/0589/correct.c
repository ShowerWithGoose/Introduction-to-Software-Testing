#include <stdio.h>
int a[1000][4];
int b[1000][5];
int n;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		b[i][0] = a[i][0], b[i][1] = a[i][1], b[i][2] = a[i][2], b[i][3] = a[i][3], b[i][4] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[k][0] == b[i][2] && a[k][1] == b[i][3]) {
					b[i][4]++;
					b[i][2] = a[k][2];
					b[i][3] = a[k][3];
					break;
				}
			}
		}
	}
	int max = 0, flag = 0;
	for (int i = 0; i < n; i++) {
		if (b[i][4] > max) {
			flag = i;
			max = b[i][4];
		}
	}
	printf("%d %d %d", b[flag][4], b[flag][0], b[flag][1]);

	return 0;
}

