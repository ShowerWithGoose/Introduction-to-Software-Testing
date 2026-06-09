#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct BSTNode {
	int data;
	struct BSTNode *lchild, *rchild;
	int Depth;
} BSTNode, *BSTree;
BSTree T;
void InsertBST(BSTree *T, int data, int Depth) {
	if (*T == NULL) {
		*T = (BSTree)malloc(sizeof(BSTNode));
		(*T)->data = data;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->Depth = Depth;
	} else if (data < (*T)->data) {
		InsertBST(&(*T)->lchild, data, Depth + 1);
	} else  {
		InsertBST(&(*T)->rchild, data, Depth + 1);
	}
}
void PreOrderTraverseBSTD(BSTree T) {
	if (!T) return; //空二叉树
	if (!T->lchild && !T->rchild)printf("%d %d\n", T->data, T->Depth); //访问根结点
	PreOrderTraverseBSTD(T->lchild); //递归遍历左子树
	PreOrderTraverseBSTD(T->rchild); //递归遍历右子树
}
int main(void) {
//	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		InsertBST(&T, data, 1);
	}
	PreOrderTraverseBSTD(T);
	return 0;
}

