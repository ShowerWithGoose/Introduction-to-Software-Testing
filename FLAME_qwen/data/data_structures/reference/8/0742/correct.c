#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[99][99], b, c, d, e, f, gg[999], mark[999], mar[999];
int h, ed, jb;

struct tu {
	int cont;
	int mark;
	struct tu *link;
} shu[99];

void insert(int k) {
	printf("%d ", k);
	int i;
	mark[k] = 1;
	for (i = 1; i < b; i++) {
		if (a[k][i] == 1 && mark[i] == 0) {
			mark[i] = 1;
			insert(i);
		}
	}

}

int  main() {
	scanf("%d", &b);
	scanf("%d", &c);
	for (int y = 0; y < c; y++) {
		scanf("%d", &d);
		scanf("%d", &e);
		a[d][e] = a[e][d] = 1;
	}

	scanf("%d", &f);
	insert(0);
	printf("\n");
	memset(mark, 0, sizeof(mark));
	memset(gg, -1, sizeof(gg));
	gg[h] = 0;
	h++;
	mar[0] = 1;
	while (gg[ed] != -1) {
		for (int y = 0; y < b; y++) {
			if (a[gg[ed]][y] != 0 && mar[y] != 1) {
				mar[y] = 1;
				gg[h] = y;
				h++;
			}
		}
		ed++;
	}
	for (int y = 0; y < b; y++) {
		printf("%d ", gg[y]);
	}
	printf("\n");
	h = 0;
	ed = 0;
	memset(gg, -1, sizeof(gg));
	memset(mar, 0, sizeof(mar));
	for (int y = 0; y < b; y++) {
		a[f][y] = 0;
		a[y][f] = 0;
	}

	insert(0);
	printf("\n");
	gg[h] = 0;
	h++;
	mar[0] = 1;
	while (gg[ed] != -1) {
		for (int y = 0; y < b; y++) {
			if (a[gg[ed]][y] != 0 && mar[y] != 1) {
				mar[y] = 1;
				gg[h] = y;
				h++;
			}
		}
		ed++;
	}
	for (int y = 0; y < h; y++) {
		printf("%d ", gg[y]);
	}

	h = 0;

	return 0;
}
