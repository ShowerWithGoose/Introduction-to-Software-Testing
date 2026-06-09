#include <stdio.h>
#include <stdlib.h>
typedef struct n {
	int num;
	int depth;
	struct n* left;
	struct n* right;
} node;
typedef node* tree;
tree insert(tree root, int data);
tree connect(tree root, node* current);
void traverse(tree t, void(*pfun)(node* p));
tree release(tree t);
void putNum(node* p) {
	printf("%d %d\n", p->num, p->depth);
}
int main() {

	tree digit;
	digit = NULL;
	int data, cnt;
	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%d", &data);
		digit = insert(digit, data);
	}
	traverse(digit, putNum);

	digit=release(digit);

	return 0;
}
tree insert(tree root, int data) {
	node* current;
	current = (node*)malloc(sizeof(node));
	current->depth = 1;
	current->num = data;
	current->left = current->right = NULL;

	return connect(root, current);


}
tree connect(tree t, node* current) {
	current->depth++;
	if (t == NULL) {
		current->depth--;
		t = current;

	} else {
		if (t->num > current->num) {
			t->left = connect(t->left, current);
		} else if (t->num <= current->num) {
			t->right = connect(t->right, current);
		}
	}
	return t;
}
void traverse(tree t, void(*pfun)(node* p)) {
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL) {
			pfun(t);
		} else {
			traverse(t->left, pfun);
			traverse(t->right, pfun);
		}
	}

}
tree release(tree t) {
	if (t != NULL) {
		t->left = release(t->left);
		t->right = release(t->right);
		free(t);
	}
	return t;
}

