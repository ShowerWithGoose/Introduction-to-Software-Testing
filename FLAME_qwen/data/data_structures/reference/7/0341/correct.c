#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:6031)

int n = 0;
int time = 0;

typedef struct Tree
{
	int data;					//	存放数据域
	struct Tree* lchild;			//	遍历左子树指针
	struct Tree* rchild;			//	遍历右子树指针
	int depth;
}Tree;

Tree tr;

void InitTree(Tree* tree)
{
	tree->rchild = NULL;
	tree->lchild = NULL;
}

Tree* FormTree(Tree* root, int n, int d)
{
	d++;
	if (root == NULL)
	{
		root = (Tree*)malloc(sizeof(Tree));
		if (root != NULL)
		{
			root->data = n;
			root->depth = d;
			InitTree(root);
		}
		else
			printf("FUCK!!!\n");
	}
	else
	{
		if (n < root->data)
			root->lchild = FormTree(root->lchild, n, d);
		else
			root->rchild = FormTree(root->rchild, n, d);
	}
	return root;
}

void PreOrderPrint(Tree* tree)
{
	if (tree != NULL)
	{
		if (tree->lchild == NULL && tree->rchild == NULL)
			printf("%d %d\n", tree->data, tree->depth);
		PreOrderPrint(tree->lchild);
		PreOrderPrint(tree->rchild);
	}
}

int main()
{
	scanf("%d", &n); 
	Tree* r = NULL;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf(" %d", &a);
		r = FormTree(r, a, 0);
	}
	PreOrderPrint(r);
	return 0;
}
