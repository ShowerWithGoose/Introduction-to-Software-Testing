#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int height;
	struct node *rchild, *lchild;
}node;

node* getNewnode(int number, int floor) {
	node *p = (node *) malloc (sizeof(node));
	p->data = number;
	p->height = floor;
	p->lchild = p->rchild = NULL;
	return p;
}

node* insert(node *root, int number, int floor) {
	if(root == NULL) {
		node *_node = getNewnode(number, floor);
		return _node;
	}
	if(number < root->data) {
		root->lchild = insert(root->lchild, number, floor + 1);
	}
	if(number >= root->data) {
		root->rchild = insert(root->rchild, number, floor + 1);
	}
	return root;
}

void output(node *root) {
	if(root->lchild == NULL && root->rchild == NULL) {
		printf("%d %d\n", root->data, root->height );
		return ;
	}
	if(root->lchild != NULL) output(root->lchild );
	if(root->rchild != NULL) output(root->rchild );
	return ;
}

int main()
{
	int sum;
	scanf("%d", &sum);
	node *root = NULL;
	int number;
	while(sum--){
		scanf("%d", &number);
		root = insert(root, number, 1);
	}
	output(root);
	return 0;
}



