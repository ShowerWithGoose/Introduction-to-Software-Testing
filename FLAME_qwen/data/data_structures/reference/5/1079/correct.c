#include <stdio.h>
int a[100][2], b[100][2], ans[10000][2];
char judge;

void bubblesort(int a[][2], int n) {
	int flag = 0, temp;

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1 - i; j++) {

			if (a[j][1] <= a[j + 1][1]) {
				temp = a[j][1];
				a[j][1] = a[j + 1][1];
				a[j + 1][1] = temp;
				temp = a[j][0];
				a[j][0] = a[j + 1][0];
				a[j + 1][0] = temp;
				flag = 1;
			}
		}

		if (flag == 0) {
			break;
		}
	}

	return;


}

int main() {
	int i = 0, j = 0, sig, pos;

	do {
		scanf("%d%d", &a[i][0], &a[i][1]);
		i++;
		judge = getchar();
	} while (judge != '\n');

	do {
		scanf("%d%d", &b[j][0], &b[j][1]);
		j++;
		judge = getchar();
	} while (judge != '\n');

	int len = 0;

	for (int k = 0; k < i; k++) {

		for (int t = 0; t < j; t++) {

			ans[len][0] = a[k][0] * b[t][0];
			ans[len][1] = a[k][1] + b[t][1];
			len++;
		}
	}

	bubblesort(ans, len);
	sig = ans[0][1];
	pos = 0;

	for (i = 1; i < len; i++) {

		if (sig == ans[i][1]) {
			ans[pos][0] += ans[i][0];
			ans[i][0] = 0;
		} else {
			sig = ans[i][1];
			pos = i;
		}
	}

	for (i = 0; i < len; i++) {

		if (ans[i][0] != 0) {
			printf("%d %d ", ans[i][0], ans[i][1]);
		}
	}

	return 0;
}

