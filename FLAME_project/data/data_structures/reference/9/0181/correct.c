#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct line {
	int x1, x2, y1, y2;
} line[150];

int cmp(const void *l1, const void *l2) {
	struct line l3 = *(struct line*)l1;
	struct line l4 = *(struct line*)l2;
	if (l3.x1 < l4.x1)
		return -1;
	if (l3.x1 == l4.x1 && l3.y1 < l4.y1)
		return -1;
	return 1;
}
int main() {
	int n = 0, i = 0, j = 0, k = 0;
	int a = 0, b = 0, c = 0, d = 0;
	int tem1 = 0, tem2 = 0;
	int length = 0, x = 0, y = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
		//	printf("%d %d %d %d", line[i].x1, line[i].y1, line[i].x2, line[i].y2);
	}
	printf("\n\n");
	qsort(line, n, sizeof(line[0]), cmp);
//	for (i = 0; i < n; i++)
	//printf("%d %d %d %d\n", line[i].x1, line[i].y1, line[i].x2, line[i].y2);

	for (i = 0; i < n; i++) {
		a = line[i].x1;
		b = line[i].y1;
		c = line[i].x2;
		d = line[i].y2;
		tem1 = a;
		tem2 = b;
		j = 1;
		while (c <= line[n - 1].x1) {
			for (k = 0; k < n; k++)
				if (line[k].x1 == c && line[k].y1 == d) {
					a = c;
					b = d;
					c = line[k].x2;
					d = line[k].y2;
					j++;
				}
			if (k == n)
				break;

		}

		if (j > length) {
			length = j;
			x = tem1;
			y = tem2;
		}
	}
	printf("%d %d %d", length, x, y);
	return 0;
}

