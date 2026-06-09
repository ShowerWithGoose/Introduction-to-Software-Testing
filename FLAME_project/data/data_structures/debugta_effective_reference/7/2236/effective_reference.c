#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
typedef struct shu
{
	int data;
	int high;
	struct shu *left;
	struct shu *right;
}tree;
tree *creat(int num0)
{
	tree *node=(tree *)malloc(sizeof(tree *));
	node->data=num0;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void insert(tree *tem,tree *root)
{
	if(tem->data>=root->data&&(root->right==NULL))
	{
		tem->right=root->right;
		root->right=tem;
	}
	else if(tem->data<root->data&&(root->left==NULL))
	{
		tem->left=root->left;
		root->left=tem;
	}
	else if(tem->data>=root->data)
	{
		insert(tem,root->right);
	}
	else
		insert(tem,root->left);
	
}
void visit(tree *root,int high)
{
	high++;
	if(root->left)
		visit(root->left,high);
	if(root->right)
		visit(root->right,high);
	if(root->left==NULL&&root->right==NULL)
		printf("%d %d\n",root->data,high);
}
int main()
{
	int i,n;
	scanf("%d",&n);
	int tem;
	scanf("%d",&tem);
	tree *root=creat(tem);
	for(i=1;i<n;i++)
	{
		scanf("%d",&tem);
		tree *t=creat(tem);
		insert(t,root);
	}
	visit(root,0);
	return 0;
}


