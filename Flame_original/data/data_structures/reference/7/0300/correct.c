#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct node														
{
	int num;
	int deep;
	struct node *left,*right; 
}; 
struct node *a;
struct node *f(struct node *tree,int num,int deep)
{
	deep++;
	if(tree==NULL)
	{
		tree=(struct node *)malloc(sizeof(struct node));
		tree->num=num;
		tree->deep=deep; 
		tree->left=NULL;
		tree->right=NULL;
		a=tree;
	}
	else if(num<tree->num)
		tree->left=f(tree->left,num,deep);
	else if(num>=tree->num)
		tree->right=f(tree->right,num,deep);
	return tree;
}
void print(struct node *tree)
{
	if(tree!=NULL)
	{
		if((tree->left==NULL)&&(tree->right)==NULL)
		{
			printf("%d %d\n",tree->num,tree->deep);
		}
		print(tree->left);
		print(tree->right);
	}
}
int main()
{
	
	struct node *tree;
	tree=NULL;
	int n=0,i=0,num=0,deep=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		deep=0;
		tree=f(tree,num,deep);
	}
	print(tree);
	return 0;
}

