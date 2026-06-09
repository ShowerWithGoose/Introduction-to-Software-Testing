#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int high;
	struct node *left,*right;
} tree;
tree *first;
tree *New(tree *root,int len,int tmp)
{
	len++;
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		if(first==NULL) first=root;
		root->data=tmp;
		root->high=len;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else
	{
		if(tmp>=root->data)
		{
			if(root->right==NULL) root->right=New(root->right,len,tmp);
			else New(root->right,len,tmp);
		}
		else
		{
			if(root->left==NULL) root->left=New(root->left,len,tmp);
			else New(root->left,len,tmp);
		}
		return root;
	}
}
void print(tree *root)
{
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->data,root->high);
	}
	else
	{
		if(root->left!=NULL)
		{
			print(root->left);
		}
		if(root->right!=NULL)
		{
			print(root->right);
		}
	}
}
int main()
{
	int n,tmp,i,len;
	tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		len=0;
		root=New(first,len,tmp);
	}
	print(first);
	return 0;
}

