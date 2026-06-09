#include <stdio.h>
#include <stdlib.h>

typedef struct line {
	int num;
	int x1, y1;
	int x2, y2;
} Line;
typedef struct line *LinePtr;

int cmp(const LinePtr e1, const LinePtr e2) {
	return e1->x1 - e2->x1;
}

int main() {
	int n;
	scanf("%d", &n);
	LinePtr list;
	list = (LinePtr)malloc(sizeof(Line) * n);
	for (int i = 0; i < n; i++) {
		list[i].num = i;
		scanf("%d %d %d %d", &list[i].x1, &list[i].y1, &list[i].x2, &list[i].y2);
	}
	qsort(list, n, sizeof(list[0]), cmp);
	int x0 = 0, y0 = 0, countmax = 0;
	for (int i = 0; i < n; i++) {
		int count = 1, xs, ys, xe, ye;
		xs = list[i].x1;
		ys = list[i].y1;
		xe = list[i].x2;
		ye = list[i].y2;
		for (int k = 0; k < n; k++) {
			if (k == i)
				continue;
			if (list[k].x1 == xe && list[k].y1 == ye) {
				count++;
				xe = list[k].x2;
				ye = list[k].y2;
			} else if (list[k].x2 == xs && list[k].y2 == ys) {
				count++;
				xs = list[k].x1;
				ys = list[k].y1;
			}
		}
		if (count > countmax) {
			countmax = count;
			x0 = xs;
			y0 = ys;
		}
	}
	printf("%d %d %d\n", countmax, x0, y0);
	return 0;
}
