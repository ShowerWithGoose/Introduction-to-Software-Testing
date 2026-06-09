#include<stdio.h>
#include <stdlib.h>
typedef struct node {
	int zhi;
	int gaodu;
	struct node *left;
	struct node *right;
} *Tree;

Tree tem,tree,tre;

Tree *creat_tree(int n)
{
	int deep=0;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		tem=(Tree)malloc(sizeof(Tree));
		tem->left=tem->right=NULL;
		scanf("%d",&tem->zhi);
			if(tree==NULL)
			{
				tem->gaodu=1;
				tree=tre=tem;
				deep=tem->gaodu;
			}
			else 
			{
				for(j=0;j<=deep;j++)
				{
					tem->gaodu=tre->gaodu;
					if(tem->zhi < tre->zhi && tre->left == NULL)
					{
						tre=tre->left=tem;
						tre->gaodu++;
						break;
					}
					else if (tem->zhi < tre->zhi && tre->left != NULL)
					{
						tre=tre->left;
					}
					else if(tem->zhi >= tre->zhi && tre->right == NULL)
					{
						tre=tre->right=tem;
						tre->gaodu++;
						break;
					}
					else 
					{
						tre=tre->right;
					}
					deep=tre->gaodu;
				}
			}
			tre=tree;
	}
	return tree;
}
void print_tre(Tree tre)
{
	if(tre != NULL)
	{
		if(tre->left==NULL&&tre->right==NULL)
		{
			printf("%d %d\n",tre->zhi,tre->gaodu);
		}
		print_tre(tre->left);
		print_tre(tre->right);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	tree = creat_tree(n);
	print_tre(tree);
	return 0;
}

