#include <stdio.h>
int a[105];
int i;

int main(void) {
	int x;
	while ( scanf("%d", &x) != EOF ) {

		if (x == 1) {
			if (i == 100) {
				printf("error ");
			} else {
				scanf("%d ", &x);
				a[i++] = x;
			}
		} else if (x == 0) {
			if (i == 0) {
				printf("error ");
			} else {
				printf("%d ", a[--i]);
			}

		} else {
			return 0;
		}

	}

	return 0;
}

