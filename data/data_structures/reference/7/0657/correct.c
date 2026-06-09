#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data,high;
	struct node *left,*right;
}BST;
BST *innode(int len,int num,BST *root)
{
	len++;
	if(root==NULL)
	{
		root=(BST*)malloc(sizeof(BST));
		root->data=num;
		root->left=root->right=NULL;
		root->high=len;
	}
	else if(num<root->data)
	{
		root->left=innode(len,num,root->left);
	}
	else if(num>=root->data)
	{
		root->right=innode(len,num,root->right);
	}
	return root;
}
void print(BST *root)
{
	if(root)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			printf("%d %d\n",root->data,root->high);
		}
		print(root->left);
		print(root->right);
	}
}
int main()
{
	BST *root=NULL;
	int n,num;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		int len=0;
		root=innode(len,num,root);
	} 
	print(root);
	return 0;
}

