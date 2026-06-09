#include <stdio.h>
#include <stdlib.h>
int x1[500], x2[500], y1[500], y2[500];

void bubblesort(int x1[], int y1[], int x2[], int y2[], int n) {
	int flag = 0, temp;

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1 - i; j++) {

			if (x1[j] > x1[j + 1]) {
				temp = x1[j];
				x1[j] = x1[j + 1];
				x1[j + 1] = temp;
				temp = x2[j];
				x2[j] = x2[j + 1];
				x2[j + 1] = temp;
				temp = y1[j];
				y1[j] = y1[j + 1];
				y1[j + 1] = temp;
				temp = y2[j];
				y2[j] = y2[j + 1];
				y2[j + 1] = temp;
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
	int n, max = 0, ansx, ansy, sum = 1, k;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}

	bubblesort(x1, y1, x2, y2, n);

	for (int i = 0; i < n; i++) {

		k = i;

		for (int j = i + 1; j < n; j++) {

			if (x1[j] == x2[k] && y1[j] == y2[k]) {
				sum++;
				k = j;
			}
		}

		if (sum > max) {
			max = sum;
			ansx = x1[i];
			ansy = y1[i];
		}

		sum = 1;
	}

	printf("%d %d %d", max, ansx, ansy);
	return 0;
}

