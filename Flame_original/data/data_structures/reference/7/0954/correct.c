#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {
	int data;
	int depth;
	struct tree *left;
	struct tree *right;
};
struct tree *createTree(struct tree *p, int num, int deep);
void findLeaf(struct tree *p);

int main() {
	int n;
	int num;
	scanf("%d", &n);
	struct tree *root = NULL;
	scanf("%d", &num);
	root = (struct tree *)malloc(sizeof(struct tree));
	root->data = num;
	root->depth = 1;
	root->left = NULL;
	root->right = NULL;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &num);
		root = createTree(root, num, root->depth);
	}

	findLeaf(root);
	return 0;
}

struct tree *createTree(struct tree *p, int num, int deep) {
	if (p == NULL) {
		p = (struct tree *)malloc(sizeof(struct tree));
		p->data = num;
		p->depth = deep;
		p->left = NULL;
		p->right = NULL;
	} else if (num < p->data) {
		p->left = createTree(p->left, num, p->depth + 1);
	} else if (num >= p->data) {
		p->right = createTree(p->right, num, p->depth + 1);
	}

	return p;
}

void findLeaf(struct tree *p) {
	if (p->left == NULL && p->right == NULL) {
		printf("%d %d\n", p->data, p->depth);
	} else if (p->left != NULL && p->right == NULL) {
		findLeaf(p->left);
	} else if (p->left == NULL && p->right != NULL) {
		findLeaf(p->right);
	} else {
		findLeaf(p->left);
		findLeaf(p->right);
	}



}


