#include <stdio.h>

int a[10], time[10];
int n;

void shuchu(int k) {
	int i = 0;
	if (k == n) {
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		if (time[i] == 0) {         //第i个数还没有用过
			a[k] = i + 1;
			time[i] = 1;            //标记第i个数，表示已经用过
			shuchu(k + 1);
			time[i] = 0;            //解除第i个数的标记
		}
	}
}


int main() {
	scanf("%d", &n);
	int k = 0;
	shuchu(k);
	return 0;
}



