#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

void leavesvisit(struct node* root,int floor)
{
	if (NULL != root->lchild)
	{
		leavesvisit(root->lchild,floor+1);
	}
	if (NULL != root->rchild)
	{
		leavesvisit(root->rchild,floor+1);
	}
	if (NULL == root->lchild && NULL == root->rchild)
	{
		printf("%d %d\n",root->data,floor);
	}
}

struct node * insert(struct node*root,int temp)
{
	struct node* p;
	if (NULL == root)
	{
		root = (struct node*)malloc(sizeof(struct node));
		root->data = temp;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else
	{
		if (temp < root->data)
		{
			if (NULL == root->lchild)
			{
				p = (struct node*)malloc(sizeof(struct node));
				p->data = temp;
				p->lchild = NULL;
				p->rchild = NULL;
				root->lchild = p;
			}
			else
			{
				root->lchild = insert(root->lchild, temp);
			}
		}
		else if (temp >= root->data)
		{
			if (NULL == root->rchild)
			{
				p = (struct node*)malloc(sizeof(struct node));
				p->data = temp;
				p->lchild = NULL;
				p->rchild = NULL;
				root->rchild = p;
			}
			else
			{
				root->rchild = insert(root->rchild, temp);
			}
		}
	}
	return root;
}

int main()
{
	struct node* root = NULL;
	int n;
	int temp;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&temp);
		root=insert(root,temp);
	}
	leavesvisit(root,1);
	return 0;
}
