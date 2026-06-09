#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tree {
	int value;
	struct tree *lchild, *rchild;
};

void search(struct tree *first, int n) {
	if (first->lchild != NULL)
		search(first->lchild, n + 1);
	if (first->rchild != NULL)
		search(first->rchild, n + 1);
	if (first->lchild == NULL && first->rchild == NULL)
		printf("%d %d\n", first->value, n);
}

int main() {
	int n;
	scanf("%d", &n);
	struct tree *first = NULL, *p, *q;
	for (int i = 0; i < n; i++) {
		int t;
		q = (struct tree *)malloc(sizeof(struct tree));
		scanf("%d", &t);
		q->value = t;
		q->lchild = NULL;
		q->rchild = NULL;
		p = first;
		if (first == NULL) {
			first = p = q;
		} else {
			while (p != NULL) {
				if (q->value < p->value) {
					if (p->lchild == NULL) {
						p->lchild = q;
						break;
					} else
						p = p->lchild;
				} else {
					if (p->rchild == NULL) {
						p->rchild = q;
						break;
					} else
						p = p->rchild;
				}
			}
		}
	}
	search(first, 1);
	return 0;
}
