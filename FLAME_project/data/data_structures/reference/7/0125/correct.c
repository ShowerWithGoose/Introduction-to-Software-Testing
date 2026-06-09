#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *lkid;
	struct TreeNode *rkid;
	int depth;
} Tree, *Treep;

int m, i, n, depth = 1;
Treep root = NULL;

void visit(Treep t) {
	printf("%d %d\n", t->val, t->depth);
}

void inorder(Treep t) {
	if (t != NULL) {
		inorder(t->lkid);
		if (t->lkid == NULL && t->rkid == NULL)
			visit(t);
		inorder(t->rkid);
	}
}

void InserTree(Treep *t, int value, int depth);

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		InserTree(&root, m, 1);
	}
	inorder(root);
	return 0;
}

void InserTree(Treep *t, int value, int depth) {
	if (*t == NULL) {
		*t = (Treep)malloc(sizeof(Treep));
		(*t)->lkid = (*t)->rkid = NULL;
		(*t)->val = value;
		(*t)->depth = depth;
	} else if (value < (*t)->val) {
		InserTree(&((*t)->lkid), value, depth + 1);
	} else {
		InserTree(&((*t)->rkid), value, depth + 1);
	}
}

