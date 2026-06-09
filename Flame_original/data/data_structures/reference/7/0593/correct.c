#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
	int data;
	int high;
	struct node *left,*right;
 }tree;
 tree *root1;
 tree *next(tree *root,int m,int h)
 {
 	h++;
 	if(root==NULL)
		{
			root=(tree*)malloc(sizeof(tree));
			root->data=m;
			root->left=root->right=NULL;
			root->high=h;
			root1=root;
		}
	else if(m<root->data)
	root->left=next(root->left,m,h);
	else if(m>=root->data)
	root->right=next(root->right,m,h);
	return root;	
 }
 void print(tree *root)
 {
 	if(root!=NULL)
 	{
 		if((root->left==NULL)&&(root->right==NULL))
 		{
 			printf("%d %d\n",root->data,root->high);
		 }
		print(root->left);
		print(root->right);
	 }
 }
 int main()
{
	int i=0,n=0,h=0,m=0;
	tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		h=0;
		scanf("%d",&m);
		root=next(root,m,h);
	}
	print(root);
	return 0;
}
 



