#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
struct node {
	int num;
	int height;
	struct node* left, * right;
};
typedef struct node tree, * treeptr;
treeptr BST(int elem, treeptr p, int high)
{
	high++;
	if (p == NULL)
	{
		p = (treeptr)malloc(sizeof(tree));
		p->num = elem;
		p->left = p->right = NULL;
		p->height = high;
	}
	else
	{
		if (elem < p->num)
		{
			p->left = BST(elem, p->left, high);
		}
		else
		{
			p->right = BST(elem, p->right, high);
		}
	}
	return p;
}

void visit(treeptr t)
{
	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL)
			printf("%d %d\n", t->num, t->height);
		visit(t->left);
		visit(t->right);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int i, elem;
	treeptr root = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		int high = 0;
		root = BST(elem, root, high);
	}
	visit(root);
	return 0;
}


