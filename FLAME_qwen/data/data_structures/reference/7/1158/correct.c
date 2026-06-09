#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct qwq {
	int data;
	int h;
	struct qwq *lc;
	struct qwq *rc;
} tree;
typedef tree *tr;
tr root = NULL;
tr q;
int i, j, k, n, hi, zhi[99];

tr insert(tr p, int item, int high) {
	high++;
	if (p == NULL) {
		p = (tr)malloc(sizeof(tree));
		p->data = item;
		p->h = high;
		p->lc = p->rc = NULL;
	} else if (item < p->data) {
		p->lc = insert(p->lc, item, high);
	} else if (item >= p->data) {
		p->rc = insert(p->rc, item, high);
	}
	return p;
}

void pri(tr s) {
	if (s != NULL) {
		if (s->lc == NULL && s->rc == NULL) {
			printf("%d %d\n", s->data, s->h);
		}
		pri(s->lc);
		pri(s->rc);
	}
}

int main( ) {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &zhi[i]);
		hi = 0;
		root = insert(root, zhi[i], hi);
	}
	pri(root);
	return 0;
}



