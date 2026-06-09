#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct tree
{
	int num;
	struct tree *left,*right;
}Tree,*PTree;

PTree createTree(PTree root,int num)
{
	if(root==NULL)
	{
		root=(PTree)malloc(sizeof(Tree));
		root->num=num;
		root->left=root->right=NULL;
		return root;
	}
	else if(num<root->num)
	{
		root->left=createTree(root->left,num);
	}
	else if(num>=root->num)
	{
		root->right=createTree(root->right,num);
	}
	return root;
}

void printL(PTree root,int height)
{
	if(root==NULL) return ;
	if(root->left!=NULL) printL(root->left,height+1);
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->num,height);
		return;
	}
	if(root->right!=NULL) printL(root->right,height+1);
}

int main()
{
	PTree root=NULL;
	int n,num,i=0;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		root=createTree(root,num);
	}
	printL(root,1);
	return 0;
}


