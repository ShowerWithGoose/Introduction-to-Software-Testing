#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct line {
	int x1;
	int y1;
	int x2;
	int y2;
};
struct line lines[105];

int cmp(const void *p, const void *q) {
	struct line *m = (struct line *)p;
	struct line *n = (struct line *)q;
	if (m->x1 < n->x1 )
		return -1;
	else if (m->x1 > n->x1 )
		return 1;
	else {
		if (m->x2 < n->x2)
			return -1;
		else if (m->x1 > n->x1)
			return 1;
	}
}

int main() {

	int n, i, maxline = 0, beginx, beginy, beginxend, beginyend, cnt = 0, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
	}
	qsort(lines, n, sizeof(struct line), cmp);
	i = 0;
	while (i < n) {
		beginxend = lines[i].x2;
		beginyend = lines[i].y2;
		cnt = 1;
		for (j = i; j < n; j++) {
			if (lines[j].x1 == beginxend && lines[j].y1 == beginyend) {
				cnt++;
				beginxend = lines[j].x2;
				beginyend = lines[j].y2;
			}
		}
		if (cnt > maxline) {
			maxline = cnt;
			beginx = lines[i].x1;
			beginy = lines[i].y1;
		}
		i++;
	}
	printf("%d %d %d\n", maxline, beginx, beginy);
}
