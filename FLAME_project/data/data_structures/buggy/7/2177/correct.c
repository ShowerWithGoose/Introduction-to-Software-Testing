#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode {
	int data;
	struct BstNode *left, *right;
} tree;

tree *insNode (tree *root, int data) {
	tree *p;
	if (root == NULL) {
		p = (tree *)malloc(sizeof(tree));
		p->data = data;
		p->left = p->right = NULL;
		return p;
	} else if (data < root->data)
		root->left = insNode(root->left, data);
	else
		root->right = insNode(root->right, data);
	return root;
}

void printLeafNode(tree *root, int hight) {
	if (root->left == NULL && root->right == NULL)
		printf("%d %d\n", root->data, hight);
	if (root->left != NULL)
		printLeafNode(root->left, hight + 1);
	if (root->right != NULL)
		printLeafNode(root->right, hight + 1);
//	if (root->left == NULL && root->right == NULL)
//		printf("%d %d\n", root->data, hight);
}

int main () {
	int n, data;
	tree *root = NULL; //root一直为根节点
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		root = insNode(root, data);
	}
	printLeafNode(root, 1);
	return 0;
}
