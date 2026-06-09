#include <stdio.h>




int count[10], vis[10] = {0}; //九个数，和分别是否在排列中的true或false
void qpl(int origin, int n) {
	if (origin == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", count[i]);
		}
		printf("\n");
	} else {
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 1) {
				continue;
			} else {
				count[origin] = i;
				vis[i] = 1; //将这个数放入排列中
				qpl(origin + 1, n); //递归处理下一个
				vis[i] = 0; //等到全排列完成一次后，将数拿出去，完成更改次序
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	qpl(0, n);
	return 0;
}


