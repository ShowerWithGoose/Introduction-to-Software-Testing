#include <stdio.h>
#include <stdlib.h>

struct L {
	int a[2];
	int b[2];
};
struct L line[100];

int judge(struct L lin1, struct L lin2) {
	if (lin1.a[0] == lin2.b[0] && lin1.a[1] == lin2.b[1])
		return 2;
	if (lin1.b[0] == lin2.a[0] && lin1.b[1] == lin2.a[1])
		return 1;
	return 0;
}

int cmp(const void *u, const void *p) {
	struct L *x = (struct L *)u;
	struct L *y = (struct L *)p;
	if (x->a[0] != y->a[0])
		return -x->a[0] + y->a[0];
	else
		return -x->a[1] + y->a[1];
}

int main() {
	int n, i, j, count[100], max = 0, ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		count[i] = 1;
	}
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[i].a[0], &line[i].a[1], &line[i].b[0], &line[i].b[1]);
	}
	qsort(line, n, sizeof(line[0]), cmp);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (judge(line[i], line[j]) == 1) {
				count[i] += count[j];
			}
			if (judge(line[i], line[j]) == 2) {
				count[j] += count[i];
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (count[i] > max) {
			max = count[i];
			ans = i;
		}
	}
	printf("%d %d %d\n", max, line[ans].a[0], line[ans].a[1]);
	return 0;
}


