#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 2000

int data[MAXSIZE];

typedef struct TreeNode
{
	int value;
	int height;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

TreeNode *bstSearch (TreeNode *T, int key)
{
	if (T)
	{
		if (key < T->value)
			return bstSearch(T->left, key);
		else
		return bstSearch(T->right, key);	
	}
	else
		return NULL;
}

void bstInsert (TreeNode **T, int key, int h)
{
	if (*T == NULL)
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->value = key;
		(*T)->left = NULL;
		(*T)->right = NULL;
		(*T)->height = h + 1;
	}
	else if (key < (*T)->value)
	{
		h++;
		bstInsert(&(*T)->left, key, h);
	}
	else
	{
		h++;
		bstInsert(&(*T)->right, key, h);
	}
}

void preOrder (TreeNode *T)
{
	if (T)
	{
		if (T->left == NULL && T->right == NULL)
			printf ("%d %d\n", T->value, T->height);
		preOrder(T->left);
		preOrder(T->right);
	}
}
int main()
{
	int n, i;
	scanf ("%d", &n);
	TreeNode* T = NULL;
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &data[i]);
		bstInsert(&T, data[i], 0);
	}
	preOrder(T);
	return 0;
}



