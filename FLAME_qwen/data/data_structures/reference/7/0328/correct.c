#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	int depth;
};
struct node *root = NULL;

void insertBST(int num) {
	struct node *p, *q;
	p = malloc(sizeof(struct node));
	p->data = num;
	p->left = NULL;
	p->right = NULL;
	if (root == NULL)
		root = p, root->depth = 1;
	else {
		int count = 2;
		q = root;
		while (1) {

			if (num < q->data) {
				if (q->left == NULL) {
					q->left = p;
					p->depth = count;
					break;
				} else
					q = q->left, count++;
			} else if (num >= q->data) {
				if (q->right == NULL) {
					q->right = p;
					p->depth = count;
					break;
				} else
					q = q->right, count++;
			}
		}
	}
}

void print(struct node *q) {
	if (q != NULL) {
		if (q->left == NULL && q->right == NULL)
			printf("%d %d\n", q->data, q->depth);
		print(q->left);
		print(q->right);
	}
}

int main() {
	int n;
	int num;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		insertBST(num);
	}
	print(root);
	return 0;
}
