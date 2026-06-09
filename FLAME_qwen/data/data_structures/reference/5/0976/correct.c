#include <stdio.h>
#include <stdlib.h>

struct xiang {
	int can;
	int ci;
};
struct xiang a1[100005], a2[100005], tmp[100005];
int cnt1 = 0, cnt2 = 0;

int cmp(const void *a, const void *b) {
	struct xiang *p1 = (struct xiang *)a;
	struct xiang *p2 = (struct xiang *)b;
	return p2->ci - p1->ci;
}

int main() {
	char c;
	int k;
	c = ' ';
	while (c != '\n') {
		scanf("%d%d%c", &a1[cnt1].can, &a1[cnt1].ci, &c);
		cnt1++;
	}
	c = ' ';
	while (c != '\n') {
		scanf("%d%d%c", &a2[cnt2].can, &a2[cnt2].ci, &c);
		cnt2++;
	}
	k = 0;
	for (int i = 0; i < cnt1; i++) {
		for (int j = 0; j < cnt2; j++) {
			tmp[k].ci = a1[i].ci + a2[j].ci;
			tmp[k].can = a1[i].can * a2[j].can;
			k++;
		}
	}
	qsort(tmp, k, sizeof(tmp[0]), cmp);
	for (int i = 0; i < k; i++) {
		if (tmp[i].ci == tmp[i + 1].ci && tmp[i].ci != 0 ) {
			tmp[i + 1].can += tmp[i].can;
			tmp[i].can = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (tmp[i].can != 0)
			printf("%d %d ", tmp[i].can, tmp[i].ci);
	}
	return 0;
}
