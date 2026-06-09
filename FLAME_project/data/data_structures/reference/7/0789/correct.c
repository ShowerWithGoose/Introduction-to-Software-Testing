#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trie{
	int data;
	struct trie *left;
	struct trie *right;
	int depth;
}Tree,*tree;
void inorder(tree a); 
tree BST(tree a,int item,int count);
int main()
{
	int n,item,i;
	tree node=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		node=BST(node,item,1);
	}
	inorder(node);
	return 0;
}
tree BST(tree a,int item,int count)
{
	if(a==NULL)
	{
		a=(tree)malloc(sizeof(Tree));
		a->data=item;
		a->left=NULL;
		a->right=NULL;
		a->depth=count;
	}
	else if(a->data<=item)
	{
		a->right=BST(a->right,item,count+1);
	}
	else if(a->data>item)
	{
		a->left=BST(a->left,item,count+1);
	}
	return a;
}
void inorder(tree a)
{
	if(a!=NULL)
	{
		inorder(a->left);
		if(a->left==NULL&&a->right==NULL)
		printf("%d %d\n",a->data,a->depth);
		inorder(a->right);
	}
}

