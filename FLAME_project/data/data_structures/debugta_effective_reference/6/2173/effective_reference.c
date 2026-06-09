#include <stdio.h>
int a[105];

int main() {
	int op, value, cnt = 0;

	while (~scanf("%d", &op)) {
		if (op == 1) {
			scanf("%d", &value);

			if (cnt < 100) {
				a[cnt] = value;
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

