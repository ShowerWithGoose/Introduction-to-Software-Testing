#include <stdio.h>
#include <string.h>

int pan(int x2, int y2, int x1, int y1  ) {
	if (x1 == x2 && y1 == y2)
		return 1;
	else
		return 0;
}

struct xid {
	int x1;
	int y1;
	int x2;
	int y2;
	int ji;
	int wei;
} xd[1000];

int main() {
	int n, i, j, k, e, max, num;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (i == n)
			scanf("%d%d%d%d", &xd[i].x1, &xd[i].y1, &xd[i].x2, &xd[i].y2);
		else
			scanf("%d%d%d%d", &xd[i].x1, &xd[i].y1, &xd[i].x2, &xd[i].y2);
	}
	for (i = 1, max = 0; i <= n; i++, max = 0) {
		for (j = 1; j <= n; j++) {
			if (pan(xd[i].x2, xd[i].y2, xd[j].x1, xd[j].y1) == 1) {
				xd[i].ji++;
				xd[i].wei = j;
			}
		}
	}
	max = 0;
	for (i = 1, num = 1; i <= n; i++, num = 1) {
		j = i;
		while (xd[j].wei) {
			num++;
			j = xd[j].wei;
		}
		if (num > max) {
			max = num;
			e = i;
		}
	}

	printf("%d %d %d", max, xd[e].x1, xd[e].y1);
	return 0;
}
