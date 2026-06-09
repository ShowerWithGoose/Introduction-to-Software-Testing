#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct BSTNode {
	int data;
	struct BSTNode *lchild, *rchild;
	int depth;
} BSTNode, *BSTree;
BSTree T;
void InsertBST(BSTree *T, int e, int depth) {
	if (*T == NULL) {
		*T = (BSTree)malloc(sizeof(BSTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->depth = depth;
	} else if (e < (*T)->data) {
		InsertBST(&(*T)->lchild, e, depth + 1);
	} else  {
		InsertBST(&(*T)->rchild, e, depth + 1);
	}
}
void PreOrder(BSTree T) {
	if (!T) return; //空二叉树
	if (!T->lchild && !T->rchild)printf("%d %d\n", T->data, T->depth); //访问根结点
	PreOrder(T->lchild); //递归遍历左子树
	PreOrder(T->rchild); //递归遍历右子树
}
int main(void) {
//	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int e;
		scanf("%d", &e);
		InsertBST(&T, e, 1);
	}
	PreOrder(T);
	return 0;
}

