#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
typedef struct shu
{
	int num;
	int ceng;
	struct shu *left;
	struct shu *right;
}tree;
tree *creat(int num0)
{
	tree *node=(tree *)malloc(sizeof(tree *));
	node->num=num0;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void insert(tree *tem,tree *root)
{
	if(tem->num>=root->num&&(root->right==NULL))
	{
		tem->right=root->right;
		root->right=tem;
	}
	else if(tem->num<root->num&&(root->left==NULL))
	{
		tem->left=root->left;
		root->left=tem;
	}
	else if(tem->num>=root->num)
	{
		insert(tem,root->right);
	}
	else
		insert(tem,root->left);
	
}
void visit(tree *root,int ceng)
{
	ceng++;
	if(root->left)
		visit(root->left,ceng);
	if(root->right)
		visit(root->right,ceng);
	if(root->left==NULL&&root->right==NULL)
		printf("%d %d\n",root->num,ceng);
}
int main()
{
	int i,n;
	scanf("%d",&n);
	int a;
	scanf("%d",&a);
	tree *root=creat(a);
	for(i=1;i<n;i++)
	{
		scanf("%d",&a);
		tree *tem=creat(a);
		insert(tem,root);
	}
	visit(root,0);
	return 0;
}


