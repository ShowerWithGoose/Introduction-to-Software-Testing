#include <stdio.h>

struct tnode {
	int data;
	int height;
	struct tnode *left;
	struct tnode *right;
};
int height = 1;

struct tnode *insertdata(struct tnode *p, int data) {
	if (p == NULL) {
		p = (struct tnode *)malloc(sizeof(struct tnode));
		p->data = data;
		p->left = NULL;
		p->right = NULL;
		p->height = height;
	} else if (data < p->data ) {
		height++;
		p->left = insertdata( p->left, data);
	} else if (data >= p->data ) {
		height++;
		p->right = insertdata( p->right, data);
	}

	height = 1;
	return p;
}

void print(struct tnode *p) {
	if (p != NULL) {
		print(p->left );
		print(p->right );

		if (p->left == NULL && p->right == NULL) {
			printf("%d %d\n", p->data, p->height );
		}
	}
}

int main() {
	int n, data;
	struct tnode *root = NULL;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &data);
		root = insertdata(root, data);
	}

	print(root);
	return 0;
}

