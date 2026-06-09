#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *lchild;
	struct node *rchlid;
	int depth;
};
typedef struct node tree;
typedef struct node *treep;
treep root = NULL;

treep InsertBST(treep t, int data, int depth) {
	treep s;
	s = (treep)malloc(sizeof(tree));
	s->data = data;
	s->depth = depth;
	s->lchild = NULL;
	s->rchlid = NULL;
	if (t == NULL) {
		t = s;

	} else {
		if (s->data < t->data) {
			t->lchild = InsertBST(t->lchild, s->data, s->depth + 1);
		} else {
			t->rchlid = InsertBST(t->rchlid, s->data, s->depth + 1);
		}
	}
	return t;
}

void shuchu(treep t) {
	if (t != NULL) {
		shuchu(t->lchild);
		if (t->lchild == NULL && t->rchlid == NULL) {
			printf("%d %d\n", t->data, t->depth);
		}

		shuchu(t->rchlid);
	}
}

int main(void) {
	int n, i, a;
	scanf("%d", &n);
	treep root = NULL;
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		root = InsertBST(root, a, 1);
	}
	shuchu(root);
	return 0;

}


