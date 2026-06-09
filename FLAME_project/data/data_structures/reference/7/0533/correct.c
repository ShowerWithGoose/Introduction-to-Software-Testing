#include <stdio.h>
#include <stdlib.h>

typedef struct BT {
	int data;
	int deep;
	struct BT *l;
	struct BT *r;
} bt;
int deep;

bt *insertBT(bt *top, int a) {
	if (top == 0) {
		top = malloc(sizeof(bt));
		top->data = a;
		top->l = top->r = 0;
		top->deep = deep;
		deep = 1;
	} else {
		deep++;
		if (a < top->data) {
			top->l = insertBT(top->l, a);
		} else {
			top->r = insertBT(top->r, a);
		}
	}
	return top;
}

void read(bt *p) {
	if (p == 0) {
		return;
	} else {
		if (p->l == p->r && p->r == 0) {
			printf("%d %d\n", p->data, p->deep);
		}
		read(p->l);
		read(p->r);
	}
}
bt *tree = 0;

int main(void) {
	int n;
	scanf("%d", &n);
	deep = 1;
	while (n--) {
		int x;
		scanf("%d", &x);
		tree = insertBT(tree, x);
	}
	read(tree);

	return 0;
}



