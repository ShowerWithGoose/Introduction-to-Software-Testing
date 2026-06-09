#include <stdio.h>
int a[105];

int main() {
	int op, data, cnt = 0;

	while (~scanf("%d", &op)) {
		if (op == 1) {
			scanf("%d", &data);

			if (cnt < 100) {
				a[cnt] = data;
				cnt++;
			} else {
				printf("error ");
			}
		} else if (op == 0) {
			if (cnt > 0) {
				cnt--;
				printf("%d ", a[cnt]);
			} else {
				printf("error ");
			}
		} else {
			return 0;
		}
	}

	return 0;
}

