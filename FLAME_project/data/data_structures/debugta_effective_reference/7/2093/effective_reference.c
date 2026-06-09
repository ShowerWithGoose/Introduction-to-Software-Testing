#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	int depth;
	struct node* lchild, * rchild;
}BTNode, * BTREE;

void INSERTBST(BTREE* root, int t)//创建线索二叉树（带层数）
{
	BTREE p = NULL, q = NULL, i = NULL;
	p = (BTREE)malloc(sizeof(BTNode));
	p->value = t;
	p->depth = 1;
	p->lchild = NULL;
	p->rchild = NULL;
	if (*root == NULL)
		*root = p;
	else
	{
		q = *root;
		while (1)
			if(t<q->value)
				if (q->lchild != NULL)
				{
					i = q;
					q = q->lchild;
					q->depth = i->depth + 1;
				}
				else
				{
					p->depth = q->depth + 1;
					q->lchild = p;
					break;
				}
			else
				if (q->rchild != NULL)
				{
					i = q;
					q = q->rchild;
					q->depth = i->depth + 1;
				}
				else
				{
					p->depth = q->depth + 1;
					q->rchild = p;
					break;
				}
	}
}

void INORDER(BTREE root)
{
	if (root != NULL)
	{
		INORDER(root->lchild);
		if (root->lchild == NULL && root->rchild == NULL)
			printf("%d %d\n", root->value, root->depth);
		INORDER(root->rchild);
	}
}

int main()
{
	int n;
	scanf("%d\n", &n);
	int t;
	int i;
	BTREE root=NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t);
		INSERTBST(&root, t);

	}

	INORDER(root);
	return 0;
}

