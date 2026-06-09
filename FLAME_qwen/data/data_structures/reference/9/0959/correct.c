#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct etc {
	int x1;
	int y1;
	int x2;
	int y2;
	int many;
};
struct etc a[100];

int cmp(const void *a, const void *b) {
	struct etc c, d;
	c = *(struct etc *)a;
	d = *(struct etc *)b;
	return (d.x2 - c.x2 );
}

int main() {
	int n;
	int i = 0;
	int max = -1;
	int maxflag = 0;
	scanf("%d", &n);
	for ( i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2 );
	}
	qsort(a, n, sizeof(struct etc), cmp);
	a[0].many = 1;
	for ( i = 0; i < n; i++) {
		int whether = 0;
		for (int j = 0; j < i; j++) {
			if (a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1) {
				a[i].many = a[j].many + 1;
				whether = 1;
				if (a[i].many > max) {
					max = a[i].many;
					maxflag = i;
				}

			}
		}
		if (whether == 0) {
			a[i].many = 1;
		}
	}
	printf("%d %d %d", max, a[maxflag].x1, a[maxflag].y1 );
}
