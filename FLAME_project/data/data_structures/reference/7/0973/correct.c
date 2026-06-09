#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *left, *right;
} Node;
typedef Node *NodePtr;
NodePtr insert(NodePtr p, int item);
void search(NodePtr p, int count);

int main() {
	int n;
	int num;
	NodePtr root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		root = insert(root, num);
	}
	search(root, 1);
	return 0;
}

NodePtr insert(NodePtr p, int item) {
	if (p == NULL) {
		p = (NodePtr)malloc(sizeof(Node));
		p->num = item;
		p->left = p->right = NULL;
	} else if (item < p->num) {
		p->left = insert(p->left, item);
	} else if (item >= p->num) {
		p->right = insert(p->right, item);
	}
	return p;
}

void search(NodePtr p, int count) {
	if (p->left == NULL && p->right == NULL) {
		printf("%d %d\n", p->num, count);
	} else if (p->left != NULL && p->right == NULL) {
		search(p->left, count + 1);
	} else if (p->left == NULL && p->right != NULL) {
		search(p->right, count + 1);
	} else if (p->left != NULL && p->right != NULL) {
		search(p->left, count + 1);
		search(p->right, count + 1);
	}
}
