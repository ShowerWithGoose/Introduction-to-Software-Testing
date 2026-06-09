#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TREE
{
	int data;
	int num;
	struct TREE *left,*right;
}tree;  
tree *first=NULL;

tree *BUILDTREE(tree *root,int temp,int fre)
{
	fre++;
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->right=root->left=NULL;
		root->data=temp;
		root->num=fre;
	}
	else if(temp>=root->data)
	    root->right=BUILDTREE(root->right,temp,fre);
	else if(temp<root->data)
	    root->left=BUILDTREE(root->left,temp,fre);
	return root;
}

void print(tree *root)
{
	if(root)
	{
		if(!root->left&&!root->right)
		printf("%d %d\n",root->data,root->num);
		print(root->left);
		print(root->right);
	}
}

int main()
{
	tree *root=NULL;
	int n,i,temp,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		t=0;
		root=BUILDTREE(root,temp,t);
	}
	print(root);
}



