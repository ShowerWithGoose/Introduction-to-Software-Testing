#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int main() {
	int a[100], p, q, i = 0;
	memset(a, -1, sizeof(-1));
	while (scanf("%d ", &p) != EOF) {
		switch (p) {
			case 1:
				scanf("%d ", &a[i]);
				i++;
				break;
			case 0:
				if (i == 0)
					printf("error ");
				else {
					printf("%d ", a[i - 1]);
					a[i] = -1;
					i--;
				}
				break;
			case -1:
				return 0;
		}
	}
	return 0;
}
