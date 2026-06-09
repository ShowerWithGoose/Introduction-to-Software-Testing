#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
	int data;
	int depth;
	struct BinaryTreeNode *lchild;
	struct BinaryTreeNode *rchild;

};

struct BinaryTreeNode *born(int num) {
	struct BinaryTreeNode *p = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	p->data = num;
	p->depth = 1;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

struct BinaryTreeNode *create_tree(int num) {
	struct BinaryTreeNode *root;
	root = born(num);
	return root;
}

void Insert(struct BinaryTreeNode *root, struct BinaryTreeNode *p) {
	if (root == NULL) {
		return;
	}

	p->depth++;

	if (root->lchild == NULL && p->data < root->data) {
		root->lchild = p;
		return;
	}

	if (root->rchild == NULL && p->data >= root->data) {
		root->rchild = p;
		return;
	}

	if (p->data < root->data) {
		Insert(root->lchild, p);
	}

	if (p->data >= root->data) {
		Insert(root->rchild, p);
	}
}

void disp(struct BinaryTreeNode *root) {
	if (root != NULL) {
		disp(root->lchild);

		if (root->lchild == NULL && root->rchild == NULL) {
			printf("%d %d\n", root->data, root->depth);
		}

		disp(root->rchild);
	}
}


int main() {
	int num_node, i, temp;
	struct BinaryTreeNode *root, *p;
	scanf("%d", &num_node);
	scanf("%d", &temp);
	root = create_tree(temp);

	for (i = 2; i <= num_node; i++) {

		scanf("%d", &temp);
		p = born(temp);
		Insert(root, p);
	}

	disp(root);
}
