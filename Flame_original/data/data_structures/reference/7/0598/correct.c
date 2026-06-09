#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
}Node;

void traverse(Node* root, int depth) {
	if (!root->left && !root->right) {
		printf("%d %d\n", root->value, depth);
		return;
	}
	if (root->left) traverse(root->left, depth + 1);
	if (root->right) traverse(root->right, depth + 1);
}

int main() {

	Node* root = NULL,* leaf = NULL;
	int value;

	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &value);
		if (!root)
			root = leaf = (Node*)malloc(sizeof(Node));
		else {
			leaf = root;
			while (1) {
				if (value >= leaf->value && leaf->right)
					leaf = leaf->right;
				else if (value >= leaf->value) {
					leaf = leaf->right = (Node*)malloc(sizeof(Node));
					break;
				}
				else if (value < leaf->value && leaf->left)
					leaf = leaf->left;
				else {
					leaf = leaf->left = (Node*)malloc(sizeof(Node));
					break;
				}
			}
		}

		leaf->value = value;
		leaf->left = NULL;
		leaf->right = NULL;

	}

	traverse(root, 1);

	return 0;
	
}
