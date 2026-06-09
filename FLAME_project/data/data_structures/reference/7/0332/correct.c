#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define OK 1
#define ERROR 0
typedef struct data {
	int value;
	int depth;
} data;
typedef data Elemtype;
typedef struct BTNode {
	Elemtype data;
	struct BTNode *lchild, *rchild;
} BTNode, *BTTree;
BTTree NewNode(BTTree, int, int);
void PreOrder(BTTree);
int main() {
	BTTree root = NULL;
	int num, value;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &value);
		root = NewNode(root, value, 0);
	}
	PreOrder(root);
	return 0;
}
BTTree NewNode(BTTree root, int value, int depth) {
	depth++;
	if (!root) {
		root = (BTTree)malloc(sizeof(BTNode));
		root->data.value = value;
		root->data.depth = depth;
		root->lchild = root->rchild = NULL;
	} else if (value < root->data.value) {
		root->lchild = NewNode(root->lchild, value, depth);
	} else if (value >= root->data.value) {
		root->rchild = NewNode(root->rchild, value, depth);
	}
	return root;
}
void PreOrder(BTTree root) {
	if (root) {
		if (!(root->lchild) && !(root->rchild))printf("%d %d\n", root->data.value, root->data.depth);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

