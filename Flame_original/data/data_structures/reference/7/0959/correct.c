#include <stdio.h>
#include <stdlib.h>

struct tree {
	int a;
	int depth;
	struct tree *lzmz;
	struct tree *rzmz;
};
struct tree *p = NULL, *q = NULL, *root = NULL;

void order(struct tree *root) {
	if (root != NULL) {
		order(root->lzmz);
		if (root->lzmz == NULL && root->rzmz == NULL) {
			printf("%d %d\n", root->a, root->depth);
		}
		order(root->rzmz);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int b;
	int m = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		q = (struct tree *)malloc(sizeof(struct tree));
		q->lzmz = NULL;
		q->rzmz = NULL;
		q->a = b;
		m = 1;
		if (root == NULL) {
			root = q;
			root->depth = 1;
		} else {
			p = root;
			while (1) {
				if (b < p->a) {
					if (p->lzmz != NULL) {
						p = p->lzmz;
						m++;
					} else {
						m++;
						p->lzmz = q;
						q->depth = m;
						break;
					}
				} else if (b >= p->a) {
					if (p->rzmz != NULL) {
						p = p->rzmz;
						m++;
					} else {
						m++;
						p->rzmz = q;
						q->depth = m;
						break;
					}
				}
			}
		}
	}
	order(root);
	return 0;
}
