#include<stdio.h>
#include<stdlib.h>
typedef struct _Bst
{
	int data;
	int height;
	struct _Bst* left, * right;
}Bst,*PBst;
PBst insertBst(PBst p, int item, int h);
void printBst(PBst p);
int main()
{
	int n, m, i;
	PBst root = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		root = insertBst(root, m,1);
	}
	printBst(root);

	return 0;
}
PBst insertBst(PBst p, int item, int h)
{
	if (p == NULL)
	{
		p = (PBst)malloc(sizeof(Bst));
		p->data = item;
		p->height = h;
		p->left = p->right = NULL;
	}
	else if (item < p->data)
		p->left = insertBst(p->left, item, h + 1);
	else 
		p->right = insertBst(p->right, item, h + 1);
	return p;
}
void printBst(PBst p)
{
	if (p == NULL)
		return;
	if (p->left != NULL)
		printBst(p->left);
	if (p->right != NULL)
		printBst(p->right);
	if (p->left == NULL && p->right == NULL)
	{
		printf("%d %d\n", p->data, p->height);
		return;
	}
		
}
