#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct TreeNode {
	int number;
	int depth;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode Tree;
typedef struct TreeNode *Treeptr;

void Insert(int a, Treeptr *t, int depth);//构建二叉树
/*
注意传入的为Treeptr *而并非Treeptr
这里可以类比在使用void函数时传入int*而非int
如果只传入Treeptr只是一个形式参数
希望t在main函数里面也要改变就要传入t的地址，即&t，也即Treeptr*
*/
void Inorder(Treeptr t);//遍历二叉树
Treeptr root = NULL;
int main() {
	int n;
	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		Insert(a, &root, 1);
	}
	Inorder(root);
	return 0;
}

void Insert(int a, Treeptr *t, int m) {
	if (*t == NULL) {
		*t = (Treeptr)malloc(sizeof(Tree));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->number = a;
		(*t)->depth = m;
	} else if (a < (*t)->number) {
		Insert(a, &((*t)->left), m + 1);
	} else {
		Insert(a, &((*t)->right), m + 1);
	}
}

void Inorder(Treeptr t) {
	if (t != NULL) {
		if ((t->left == NULL) && (t->right == NULL)) {
			printf("%d %d\n", t->number, t->depth);
		}
		Inorder(t->left);
		Inorder(t->right);
	}
}

