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
	LinePtr x1;
	x1 = (LinePtr)malloc(sizeof(Line) * n);
	for (int i = 0; i < n; i++) {
		x1[i].num = i;
		scanf("%d %d %d %d", &x1[i].x1, &x1[i].y1, &x1[i].x2, &x1[i].y2);
	}
	qsort(x1, n, sizeof(x1[0]), cmp);
	int x0 = 0, y0 = 0, countmax = 0;
	for (int i = 0; i < n; i++) {
		int count = 1, xs, ys, xe, ye;
		xs = x1[i].x1;
		ys = x1[i].y1;
		xe = x1[i].x2;
		ye = x1[i].y2;
		for (int j = 0; j < n; j++) {
			if (j == i)
				continue;
			if (x1[j].x1 == xe && x1[j].y1 == ye) {
				count++;
				xe = x1[j].x2;
				ye = x1[j].y2;
			} else if (x1[j].x2 == xs && x1[j].y2 == ys) {
				count++;
				xs = x1[j].x1;
				ys = x1[j].y1;
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
