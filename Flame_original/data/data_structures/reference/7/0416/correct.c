#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct tree{
	int data;
	int floor;
	struct tree *left,*right;
	
}tree;

tree *head;
tree *build(tree *root,int temp,int depth);

int temp;
void put(tree *root);
int depth;

int main()
{
	int n;
	tree *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		depth=0;
		scanf("%d",&temp);
		root=build(root,temp,depth);
	}
	put(root);
	return 0;
} 

tree *build(tree *root,int temp,int depth)
{
	depth++;
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=temp;
		root->left=NULL;
		root->right=NULL;
		head=root;
		root->floor=depth;
	}
	else if(temp<root->data)
	{
		root->left=build(root->left,temp,depth);
	}
	else if(temp>=root->data)
	{
		root->right=build(root->right,temp,depth);
	}
	return root;
}

void put(tree *root)
{
	if(root)
	{
		if(!(root->left) && !(root->right))
		{
			printf("%d %d\n",root->data,root->floor);
		}
		put(root->left);
		put(root->right);
	}
} 

