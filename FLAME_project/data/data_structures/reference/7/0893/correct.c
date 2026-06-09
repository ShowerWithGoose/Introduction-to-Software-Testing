#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
	int data;
	int depth;
	struct node *left,*right;
}BTree,*BList;
BList first;

BList createnode(BList root,int temp,int len)
{
	len++;
	if(root==NULL)
	{
		root=(BList)malloc(sizeof(BTree));
		root->data=temp;
		root->left=NULL;
		root->right=NULL;
		first=root;
		root->depth=len;
	}
	else if(temp<root->data)
	{
		root->left=createnode(root->left,temp,len);
	}
	else if(temp>=root->data)
	{
		root->right=createnode(root->right,temp,len);
	}
	return root;
}

void print(BList root)
{
	if(root)
	{
		if(!(root->left)&&!(root->right))
		{
			printf("%d %d\n",root->data,root->depth);
		}
		print(root->left);
		print(root->right);
	}
}

int main()
{
	BList root=NULL;
	int n,temp,i=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &temp);
		int len=0;
		root=createnode(root,temp,len);
	}
	print(root);
	return 0;
}

