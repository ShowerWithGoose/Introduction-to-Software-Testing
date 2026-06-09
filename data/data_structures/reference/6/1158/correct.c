#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int zhan[100], i, j, m, n, p;

int main( ) {
	while (1) {
		scanf("%d", &n);
		if (n == 1) {
			scanf("%d", &m);
			if (p == 99) {
				printf("error ");
			} else {
				zhan[p] = m;
				p++;
			}
		} else if (n == 0) {
			if (p == 0) {
				printf("error ");
			} else {
				p--;
				printf("%d ", zhan[p]);
				zhan[p] = 0;
			}
		} else if (n == -1) {
			break;
		}
	}
	return 0;
}

