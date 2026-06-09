#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int h = 1;

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
} *BTnodeptr, BTnode;

BTnodeptr insertTree(BTnodeptr p, int item) {
	if (p == NULL) {
		p = (BTnodeptr)malloc(sizeof(BTnode));
		p->data = item;
		p->left = NULL;
		p->right = NULL;
	} else {
		if (item < p->data)
			p->left = insertTree(p->left, item);
		else if (item >  p->data || item == p->data)
			p->right = insertTree(p->right, item);
	}
	return p;
}

void preorder(BTnodeptr p) {
	if (p == NULL)
		return;
	else {
		if (p->left == NULL && p->right == NULL)
			printf("%d %d\n", p->data, h);
		h++;
		preorder(p->left);
		preorder(p->right);
		h--;
	}
}

int main() {

	int n, num, i;
	BTnodeptr root = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		root = insertTree(root, num);
	}
	preorder(root);
	return 0;
}
