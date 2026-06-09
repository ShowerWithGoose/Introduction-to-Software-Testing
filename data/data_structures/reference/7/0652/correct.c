#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int high;
	struct node *left;
	struct node *right;
}Node,*Tree; 
void insert(Tree *tree,int value,int depth)
{
	if(*tree==NULL)
	{
		*tree=(Tree)malloc(sizeof(Tree));
		(*tree)->left=NULL;
		(*tree)->right=NULL;
		(*tree)->high=depth;
		(*tree)->data=value; 
	}
	else if(value<(*tree)->data)
	insert(&((*tree)->left),value,depth+1);
	else
	insert(&((*tree)->right),value,depth+1);
}
void visit(Tree tree)
{
	if(tree!=NULL)
	{
		visit(tree->left);
		if(tree->left==NULL&&tree->right==NULL)
		printf("%d %d\n",tree->data,tree->high);
		visit(tree->right);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,x;
	Tree tree=NULL;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		insert(&tree,x,1);
	}
	visit(tree);
	return 0;
}

