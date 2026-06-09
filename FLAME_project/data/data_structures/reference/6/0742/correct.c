#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[999], k, t, g;
int *p;

int main() {

	while (1) {
		scanf("%d", &k);
		if (k == 1) {
			if (g != 99) {
				scanf("%d", &t);
				g++;
				a[g] = t;
			} else
				printf("error ");
		} else if (k == 0) {
			if (g == 0) {
				printf("error ");
				continue;
			} else {
				printf("%d ", a[g]);
				g--;
			}

		} else if (k == -1) {
			break;

		}
	}
	printf("\b");



	return 0;
}

