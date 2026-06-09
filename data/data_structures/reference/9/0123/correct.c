#include <stdio.h>

struct xianduan {
	int x1;
	int y1;
	int x2;
	int y2;
	int count;
};

int main(void) {
	struct xianduan a[1000];
	struct xianduan tmp;
	int count_max = 0, i, j, n, x2, y2;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		a[i].count = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (a[i].x1 > a[j].x1) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	count_max = a[1].count;
	for (i = 1; i <= n; i++) {
		x2 = a[i].x2;
		y2 = a[i].y2;
		for (j = i; j <= n; j++) {
			if (x2 == a[j].x1 && y2 == a[j].y1) {
				x2 = a[j].x2;
				y2 = a[j].y2;
				a[i].count++;
			}
		}
		if (a[i].count > count_max) {
			a[0] = a[i];
			count_max = a[i].count;
		}
	}
	printf("%d %d %d", a[0].count, a[0].x1, a[0].y1);
	return 0;
}



