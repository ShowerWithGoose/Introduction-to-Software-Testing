#include <stdio.h>
#include <stdlib.h>

struct BstNode {
	int data;
	struct BstNode *left, *right;
};

struct BstNode *insNode(struct BstNode *root, int data) {
	struct BstNode *p;
	if (root == NULL) {
		p = (struct BstNode *)malloc(sizeof(struct BstNode));
		p->data = data;
		p->left = p->right = NULL;
		return p;
	} else if (data < root->data)
		root->left = insNode(root->left, data);
	else
		root->right = insNode(root->right, data);
	return root;
}

void printLeafNode(struct BstNode *root, int hight) {
	if (root->left != NULL)
		printLeafNode(root->left, hight + 1);
	if (root->right != NULL)
		printLeafNode(root->right, hight + 1);
	if (root->left == NULL && root->left == NULL)
		printf("%d %d\n", root->data, hight);
}

int main () {
	int n, data;
	struct BstNode *root = NULL; //root一直为根节点
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		root = insNode(root, data);
	}
	printLeafNode(root, 1);
	return 0;
}
