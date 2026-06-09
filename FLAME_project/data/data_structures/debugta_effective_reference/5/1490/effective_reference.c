#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct math {
	int fac;
	int pow;
};
typedef struct math mul;
mul a[2000], b[2000], c[2000];
int cmp(const void *p1, const void *p2);

int main() {
	int i, j, n = 0, m = 0;
	char ch;
	while (1) {
		scanf("%d%d%c", &a[n].fac, &a[n].pow, &ch);
		n++;
		if (ch == '\n') {
			break;
			n--;
		}
	}
	while (1) {
		scanf("%d%d%c", &b[m].fac, &b[m].pow, &ch);
		m++;
		if (ch == '\n') {
			break;
			m--;
		}
	}
	int k = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			c[k].fac = a[i].fac * b[j].fac;
			c[k].pow = a[i].pow + b[j].pow;
			k++;
		}
	}
	for (i = 0; i < n * m; i++) {
		for (j = i + 1; j < n * m; j++) {
			if (c[i].pow == c[j].pow && c[j].pow != 0) {
				c[j].fac += c[i].fac;
				c[i].fac = 0;
			}
		}
	}
	qsort(c, n * m, sizeof(mul), cmp);
	for (i = 0; i < n * m; i++) {
		if (c[i].fac == 0) {
			continue;
		} else {
			printf("%d %d ", c[i].fac, c[i].pow);
		}
	}
	return 0;
}

int cmp(const void *p1, const void *p2) {
	struct math *a = (struct math *)p1;
	struct math *b = (struct math *)p2;
	return b->pow - a->pow;
}

