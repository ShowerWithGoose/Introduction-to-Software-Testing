#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	int high;
	struct node  *left,*right;
}tree;

tree *first;
tree *New(tree *root, int temp,int len);
void print(tree *root); 


int main()
{
	tree *root =NULL;
	int n,temp;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		int len=0;
		root = New (root,temp,len);
	}
	print(root);
	return 0;
}


tree *New(tree *root, int temp,int len)
{
	len++;
	if(root == NULL)
	{
		root = (tree *)malloc(sizeof(tree));
		root->num = temp;
		root ->left =root->right=NULL;
		first = root;
		root->high =len;
	}
	else if(temp < root -> num )  root->left = New(root->left,temp,len);
	else if(temp >= root ->num )  root->right = New(root->right,temp,len);
	return root;
}


void print(tree *root)
{
	if (root)
	{
		if(!(root->left) && !(root->right))  printf("%d %d\n",root->num,root->high);
		print(root->left);
		print(root->right);      
	}
}





















