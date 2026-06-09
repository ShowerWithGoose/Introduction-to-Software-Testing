#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n;

int main() {
	int i, j, k, a, b;
	int out[100], outs[100];
	outs[1] = 1, outs[0] = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		outs[i + 1] = (i + 1) * outs[i];
		out[i] = i;
	}
	for (a = 1; a <= n; a++) {
		printf("%d ", out[a]);
	}
	printf("\n");
	for (i = 1; i <= outs[n] - 1; i++) {
		for (j = n - 1; j >= 1; j--) {
			if (out[j] <= out[j + 1]) {
				break;
			}
		}
		for (k = n; k >= 1; k--) {
			if (out[k] > out[j]) {
				break;
			}
		}
		int temp = out[k];
		out[k] = out[j];
		out[j] = temp;
		for (a = j + 1, b = n; a < b; a++, b--) {
			temp = out[a];
			out[a] = out[b];
			out[b] = temp;
		}
		for (a = 1; a <= n; a++) {
			printf("%d ", out[a]);
		}
		printf("\n");

	}




	return 0;
}



