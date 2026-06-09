#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct bstree{
	int data;
	int high;
	struct bstree *lchild;
	struct bstree *rchild;
};

typedef struct bstree bstree;

bstree* insert(bstree *t,int num,int h)
{
	bstree *a,*b;
	a = (bstree*)malloc(sizeof(bstree));
	a->data = num;
	a->high = h;
	a->lchild = NULL;
	a->rchild = NULL;
	if(t == NULL)
	{
		t = a;
	}
	else
	{
		b = t;
		while(1)
		{
			a->high++;
			if(num < b->data)
			{
				if(b->lchild == NULL)
				{
					b->lchild = a;
					break;
				}
				else
					b = b->lchild;
			}
			else if(num >= b->data)
			{
				if(b->rchild == NULL)
				{
					b->rchild = a;
					break;
				}
				else
					b = b->rchild;
			}
		}
	}
	return t;
}

void print_leaf(bstree *t)
{
	if(t != NULL)
	{
		if(t->lchild == NULL && t->rchild == NULL)
		{
			printf("%d %d\n",t->data,t->high);
		}
		print_leaf(t->lchild);
		print_leaf(t->rchild);
	}
}

int main()
{
	bstree *root = NULL;
	
	int n;
	scanf("%d\n",&n);
	
	int i;
	int item;
	int item_h;
	int root_h = 1;
	for(i = 0;i < n;i++)
	{
		item_h = root_h;
		scanf("%d",&item);
		root = insert(root,item,item_h);
	}
	
	print_leaf(root);
	return 0;
}
