
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct treenode
{
	int a;
	struct treenode *left;
	struct treenode *right;
	int deep;
}tree,*treep;
treep root;
void visit(treep t)
{
	printf("%d %d\n",t->a,t->deep);
}
treep treebst(treep t,int m,int n)
{
	if((t)==NULL)
	{
		
		(t)=(struct treenode*)malloc(sizeof(struct treenode));
		(t)->left=(t)->right=NULL;
		(t)->a=m;
		(t)->deep=n;
		//printf("%d %d\n",t->a,t->deep);
	}
	else if(m<(t->a))
	{
		t->left=treebst(t->left,m,n+1);
	}
	else
	{
		t->right=treebst(t->right,m,n+1);
	}
	return t;
}
void inorder(treep t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->right==NULL&&t->left==NULL)
		visit(t);
		inorder(t->right);
	}
}
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		root=treebst(root,j,1);//每次从头寻找应该在的位置，并非递归 
	}
	
	inorder(root);
}


