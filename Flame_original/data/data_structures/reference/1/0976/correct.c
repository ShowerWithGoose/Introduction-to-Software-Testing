#include <stdio.h>
int n[15], flag[15];
int N;
void pai(int m);

int main() {
	scanf("%d", &N);
	pai(N);
	return 0;
}


void pai(int m) {
	if (m == 0) {
		for (int i = 0; i < N; i++)
			printf("%d ", n[i]);
		printf("\n");
		return;
	} else {
		for (int i = 1; i <= N; i++) {
			if (flag[i] == 0) {
				n[N - m] = i;
				flag[i] = 1;
				pai(m - 1);
				flag[i] = 0;
			}
		}
	}
}


