#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node   *lchild,  *rchild;
	int depth;
};
typedef struct node  tree;
typedef struct node  *treep;
int dep = 1;

void VISIT(treep t) {
	if (t->lchild == NULL && t->rchild == NULL) {
		printf("%d %d\n", t->data, t->depth);
	}
}

void perorder(treep t) {
	if (t != NULL) {
		VISIT(t);/* 访问t指向结点  */
		perorder(t->lchild);
		perorder(t->rchild);
	}
}

treep inserttree(treep p, int a, int dep) {
	if (p == NULL) {
		p = (treep)malloc(sizeof(tree));
		p->data = a;
		p->lchild = p->rchild = NULL;
		p->depth = dep;
	} else if (a < p->data) {
		p->lchild = inserttree(p->lchild, a, dep + 1);
	} else {
		p->rchild = inserttree(p->rchild, a, dep + 1);
	}
	return p;
}

int main() {
	int n, item;
	treep root = NULL;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &item);
		root = inserttree(root, item, dep);
	}
	perorder(root);
	return 0;
}
