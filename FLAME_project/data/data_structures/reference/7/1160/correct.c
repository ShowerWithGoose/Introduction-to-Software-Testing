#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct node{
	ElemType data;
	struct node *llink;
	struct node *rlink;
} BTree;

BTree *InitialBTree()
{
	BTree *root = (BTree*)malloc(sizeof(BTree));
	root->data = 0;
	root->llink = NULL;
	root->rlink = NULL;
	return root;
}

void Visit(BTree *t)
{
	printf("%d",t->data);
}

void PreorderTraversal(BTree *t) // DLR
{
	if (t != NULL)
	{
		Visit(t);
		PreorderTraversal(t->llink);
		PreorderTraversal(t->rlink);
	}
}

void InorderTraversal(BTree *t) // LDR
{
	if (t != NULL)
	{
		InorderTraversal(t->llink);
		Visit(t);
		InorderTraversal(t->rlink);
	}
}

void PostorderTraversal(BTree *t) // LRD
{
	if (t != NULL)
	{
		PostorderTraversal(t->llink);
		PostorderTraversal(t->rlink);
		Visit(t);
	}
}

void VisitWithHeight(BTree *t, int height)
{
	if (t->llink == NULL && t->rlink == NULL)
	{
		printf("%d %d\n",t->data,height);
	}
}

void PreorderTraversalWithHeight(BTree *t, int height) // DLR
{
	if (t != NULL)
	{
		height++;
		VisitWithHeight(t, height - 1);
		PreorderTraversalWithHeight(t->llink, height);
		PreorderTraversalWithHeight(t->rlink, height);
	}
}

void InorderTraversalWithHeight(BTree *t, int height) // LDR
{
	if (t != NULL)
	{
		height++;
		InorderTraversalWithHeight(t->llink, height);
		VisitWithHeight(t, height - 1);
		InorderTraversalWithHeight(t->rlink, height);
	}
}

void PostorderTraversalWithHeight(BTree *t, int height) // LRD
{
	if (t != NULL)
	{
		height++;
		PostorderTraversalWithHeight(t->llink, height);
		PostorderTraversalWithHeight(t->rlink, height);
		VisitWithHeight(t, height - 1);
	}
}

int main()
{
	BTree *root = InitialBTree();
	int n;
	scanf("%d",&n);
	int first;
	scanf("%d",&first);
	root->data = first;
	for (int i = 0; i < n - 1; i++)
	{
		int this;
		scanf("%d",&this);
		BTree *op = root;
		int flag = 1;
		while (flag)
		{
			if (this < op->data)
			{
				if (op->llink != NULL)
				{
					op = op->llink;
				}
				else
				{
					op->llink = InitialBTree();
					op = op->llink;
					op->data = this;
					flag = 0;
				}
			}
			else
			{
				if (op->rlink != NULL)
				{
					op = op->rlink;
				}
				else
				{
					op->rlink = InitialBTree();
					op = op->rlink;
					op->data = this;
					flag = 0;
				}
			}
		}
	}
	PreorderTraversalWithHeight(root, 1);

	return 0;
}
