#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

typedef struct BiTree
{
	int node;
	int height;
	struct BiTree *left,*right;
}tree,*btree;
btree root = NULL;

void bianli(btree a);
void creatt(btree *a,int height,int n);


int main()
{
	int i,j,k,n,nodez;
	scanf ("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf ("%d",&nodez);
		creatt (&root,1,nodez);
	}
	bianli(root);
	
	return 0;
}


void bianli (btree a)
{
	if(a!= NULL)//遍历访问至叶子 
	{
		bianli(a->left);
		if (a->left == NULL && a->right == NULL) 
			printf ("%d %d\n",a->node,a->height);
		bianli(a->right);
	}
}
void creatt(btree *a,int height,int n)
{
	if (*a == NULL)
	{
		*a = (btree)malloc(sizeof(btree));
		(*a)->node = n;
		(*a)->height = height;
		(*a)->left = (*a)->right = NULL;
		
	}
	else if (n<(*a)->node) //小于在左 
		creatt(&((*a)->left),height+1,n);
	else
		creatt(&((*a)->right),height+1,n);
}

