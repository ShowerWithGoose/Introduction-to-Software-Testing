#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num,height;
	struct node *left,*right;
}treeNode; 

treeNode *creatTree(treeNode *root,int temp,int len);//在树中增加结点
void printTree(treeNode *root);//打印树的叶结点 

int main()
{
	int n,i,temp,len=0;
	treeNode *root=NULL;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		root=creatTree(root,temp,len);
	}
	
	printTree(root);
	return 0;
	
}

treeNode *creatTree(treeNode *root,int temp,int len)
{
	len++;
	if(root==NULL)
	{
		root=(treeNode *)malloc(sizeof(treeNode));
		root->left=root->right=NULL;
		root->height=len;
		root->num=temp;
	}
	
	else if(root->num<=temp)
		root->right=creatTree(root->right,temp,len);
		
	else if(root->num>temp)
		root->left=creatTree(root->left,temp,len);
		
	return root;
}

void printTree(treeNode *root)
{
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->num,root->height);
		return;
	}
		
	if(root->left!=NULL)
		printTree(root->left);
		
	if(root->right!=NULL)
		printTree(root->right);
}

