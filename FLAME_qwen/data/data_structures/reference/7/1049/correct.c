#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int high;
	struct node *left, *right;
} Tree;

Tree *setup(Tree *root, int temp, int len) {
	len++;
	if (root == NULL) {
		root = (Tree *)malloc(sizeof(Tree));
		root->data = temp;
		root->high = len;
		root->left = NULL, root->right = NULL;
	} else {
		if (temp >= root->data) {
			root->right = setup(root->right, temp, len);
		} else {
			root->left = setup(root->left, temp, len);
		}
	}
	return root;
}

void printree(Tree *root) {
	if (root) {
		if (!(root->right) && !(root->left)) {
			printf("%d %d\n", root->data, root->high);
		}
		printree(root->left);
		printree(root->right);
	}
}

int main() {
	int i, j, n, temp, len = 0;
	Tree *root = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		root = setup(root, temp, len);
	}
	printree(root);


	return 0;
}


