#include <stdio.h>
#include <stdlib.h>

struct line {
	int x1;
	int x2;
	int y1;
	int y2;
	int num;
};
struct line l[10005];

int cmp(const void *a, const void *b) {
	struct line *p1 = (struct line *)a;
	struct line *p2 = (struct line *)b;
	if (p1->x1 != p2->x1)
		return p2->x1 - p1->x1;
	else
		return p2->y1 - p1->y1;
}

int main() {
	int n, max = -1, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
		l[i].num = 1;
	}
	qsort(l, n, sizeof(l[0]), cmp);
	for (int i = 0; i < n - 1; i++ ) {
		for (int j = i; j < n - 1; j++) {
			if (l[i].x1 == l[j + 1].x2 && l[i].y1 == l[j + 1].y2)
				l[j + 1].num += l[i].num;
		}
	}
	for (int i = 0; i < n; i++) {
		if (l[i].num > max)
			max = l[i].num, flag = i;
	}
	printf("%d %d %d", max, l[flag].x1, l[flag].y1);
	return 0;
}
