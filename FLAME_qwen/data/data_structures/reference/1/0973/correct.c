#include <stdio.h>




int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b[10] = {}, N;



void print() {
	for (int i = 0; i < N; i++) {
		printf("%d ", a[b[i]]);
	}
	printf("\n");
}

void op(int n) {
	int flag = 0;
	if (n == 0) {
		print();
		return;
	}
	for (int k = 0; k < N; k++) {
		for (int k1 = 0; k1 < N - n; k1++) {
			if (k == b[k1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			flag = 0;
			continue;
		}
		b[N - n] = k;
		op(n - 1);
	}
}

int main() {
	scanf("%d", &N);
	op(N);
	return 0;
}


