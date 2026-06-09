#include <stdio.h>
#include <stdlib.h>

struct BstNode {
	int data;
	struct BstNode *lchild, *rchild;
};

struct BstNode* insnode(struct BstNode* root, int data)
{
	struct BstNode* p;
	if (root == NULL)
	{
		p = (struct BstNode*)malloc(sizeof(struct BstNode));
		p->data = data;
		p->lchild = p->rchild = NULL;
		return p;
	}
	else if(data < root->data)
		root->lchild = insnode(root->lchild, data);
	else
		root->rchild = insnode(root->rchild, data);
	return root;
}//递归方式创造二叉查找树

void printleaf(struct BstNode* root, int high)
{
	if (root->lchild != NULL)
		printleaf(root->lchild, high + 1);
	if (root->rchild != NULL)
		printleaf(root->rchild, high + 1);
	if (root->lchild == NULL && root->rchild == NULL)
		printf("%d %d\n", root->data, high);
}

int main()
{
	struct BstNode* root = NULL;
	int n, data, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &data);
		root = insnode(root, data);
	}
	printleaf(root, 1);
	return 0;
}


