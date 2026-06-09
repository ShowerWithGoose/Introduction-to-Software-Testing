#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int jk, num, t;

struct tree {
	struct tree *le;
	struct tree *ri;
	int depth;
	int cont;
	int mark;
};
typedef struct tree tre, *root;

root create(root p, int k) {
	int hh = 0;
	if (p == NULL) {
		p = (root)malloc(sizeof(tre));
		p->cont = k;
		p->le = p->ri = NULL;
	} else {
		if (k < p->cont) {
			p->le = create(p->le, k);
		} else if (k >= p->cont) {
			p->ri = create(p->ri, k);
		}
	}
	return p;
}

void find(root h) {
	if (h != NULL) {
		if (h->le != NULL) {
			h->le->depth = h->depth + 1;
		}
		if (h->ri != NULL) {
			h->ri->depth = h->depth + 1;
		}
		find(h->le);
		if (h->le == NULL && h->ri == NULL) {
			printf("%d %d\n", h->cont, h->depth);
		}
		find(h->ri);
	}
}

void insert(root y) {
	if (y != NULL) {
		insert(y->le);
		if (y->le == NULL && y->ri == NULL) {
			printf("%d ", y->cont);
		}
		insert(y->ri);
	}
}

//13
//50 38 30 64 58 40 10 73 70 50 60 100 35
int main() {
	scanf("%d", &num);
	root rot = NULL;
	for ( t = 0; t < num; t++) {
		scanf("%d", &jk);
		rot = create(rot, jk);
	}
	rot->depth = 1;
//	insert(rot);
	find(rot);
	return 0;
}
