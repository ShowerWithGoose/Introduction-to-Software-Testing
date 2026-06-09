#include <stdio.h>
#include <math.h>

struct line {
	int x1, y1, x2, y2;
	int v;
} l[105];
int n;
int mc = 0;
int mn;

void ser(int p, int cnt, int k) {
	for (int i = 1; i <= n; i++) {

		if (p == i)
			continue;

		if (l[p].x2 == l[i].x1 && l[p].y2 == l[i].y1) {
			cnt++;
			ser(i, cnt, k);
			return;
		}
	}

	if (mc < cnt) {
		mc = cnt;
		mn = k;
	}

	return;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		scanf("%d%d%d%d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
		l[i].v = 0;
	}

	for (int i = 1; i <= n; i++) {

		ser(i, 1, i);
	}

	printf("%d %d %d", mc,l[mn].x1,l[mn].y1);
	return 0;
}
