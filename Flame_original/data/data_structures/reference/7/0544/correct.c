#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	int depth;
	struct node* lchild, * rchild;
}BTNode, * BTREE;

void INSERTBST(BTREE* T, int item)//创建线索二叉树（带层数）
{
	BTREE p = NULL, q = NULL, r = NULL;
	p = (BTREE)malloc(sizeof(BTNode));
	p->value = item;
	p->depth = 1;
	p->lchild = NULL;
	p->rchild = NULL;
	if (*T == NULL)
		*T = p;
	else
	{
		q = *T;
		while (1)
			if(item<q->value)
				if (q->lchild != NULL)
				{
					r = q;
					q = q->lchild;
					q->depth = r->depth + 1;
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
					r = q;
					q = q->rchild;
					q->depth = r->depth + 1;
				}
				else
				{
					p->depth = q->depth + 1;
					q->rchild = p;
					break;
				}
	}
}

void INORDER(BTREE T)
{
	if (T != NULL)
	{
		INORDER(T->lchild);
		if (T->lchild == NULL && T->rchild == NULL)
			printf("%d %d\n", T->value, T->depth);
		INORDER(T->rchild);
	}
}

int main()
{
	int num;
	scanf("%d\n", &num);
	int item;
	int i;
	BTREE T=NULL;
	for (i = 0; i < num; i++)
	{
		scanf("%d", &item);
		INSERTBST(&T, item);

	}

	INORDER(T);
	return 0;
}

