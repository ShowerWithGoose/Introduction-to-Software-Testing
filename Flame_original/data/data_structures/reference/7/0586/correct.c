#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	int val;
	int high;
	struct node *left;
	struct node *right;
} tree;

tree *add(tree *root, int num, int high) {
	high++;
	if (root == NULL) {
		root = (tree *)malloc(sizeof(tree));
		root->val = num;
		root->left = NULL;
		root->right = NULL;
		root->high = high;
	} else {
		if (num >= root->val)
			root->right = add(root->right, num, high);
		else if (num < root->val)
			root->left = add(root->left, num, high);
	}
	return root;
}

void pr(tree *root) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL)
			printf("%d %d\n", root->val, root->high);

		pr(root->left);
		pr(root->right);
	}
}

int main() {
	tree *root = NULL;
	int n, i, num, high = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		root = add(root, num, high);
	}
	pr(root);
	return 0;
}

