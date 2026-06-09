#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct TreeNode {
	int number;
	int depth;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode Tree;
typedef struct TreeNode *Treeptr;

void Insert(int a, Treeptr *t, int depth);
void Inorder(Treeptr t);
Treeptr root = NULL;
int main() {
	int n;
	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		Insert(a, root, 1);
	}
	Inorder(root);
	return 0;
}

void Insert(int a, Treeptr *t, int m) {
	if (*t == NULL) {
		*t = (Treeptr)malloc(sizeof(Treeptr));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->number = a;
		(*t)->depth = m;
	} else if (a < (*t)->number) {
		Insert(a, &((*t)->left), m + 1);
	} else {
		Insert(a, &((*t)->right), m + 1);
	}
	return t;
}

void Inorder(Treeptr t) {
	if (t != NULL) {
		if ((t->left == NULL) && (t->right == NULL)) {
			printf("%d %d\n", t->number, t->depth);
		}
		Inorder(t->left);
		Inorder(t->right);
	}
}

