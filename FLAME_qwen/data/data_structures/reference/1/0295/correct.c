#include <stdio.h>
#include <stdlib.h>
int arr[15];
int flag[15];
void put(int n) {
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void arry(int d, int n) {
	if (1 && d - 1 == n) {

		put(n);

		return ;
	}
	int i;
	for (i = 1; i <= n; i++) {
		if (flag[i]) {
			continue;
		} else {
			flag[i] = 1;
			arr[d] = i;
			arry(d + 1, n);
			flag[i] = 0;
		}
	}

}
int main() {

	int n;
	scanf("%d", &n);
	arry(1, n);

	return 0;
}



