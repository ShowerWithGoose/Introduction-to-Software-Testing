#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int Data;
	struct tree* left,* right;
};
typedef struct tree BTNode,*BTNodePtr;
BTNodePtr insert_tree(int data,BTNodePtr root );
void findleaves(BTNodePtr root,int i);
int main()
{
	BTNodePtr root=NULL;
	int n,i,data;scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data);
		root=insert_tree(data,root);
	}
	findleaves(root,1);
	return 0;
}
BTNodePtr insert_tree(int data,BTNodePtr root)
{
	if(root==NULL)
	{
		root=(BTNodePtr)malloc(sizeof(BTNode));
		root->Data=data;
		root->left=root->right=NULL;
	}
	else if(data< root->Data)
		root->left=insert_tree(data,root->left);
	else if(data>=root->Data)
		root->right=insert_tree(data,root->right);
	return root;
}
/*void findleaves(BTNodePtr biotree,int i)
{
	if(biotree->left==NULL)
	{
	//	printf("%d %d\n",biotree->Data,i);
	}
	else
	{
		findleaves(biotree->left,i+1);	
	}
	if(biotree->right==NULL)
	{
		printf("%d %d\n",biotree->Data,i);
	}
	else
	{
		findleaves(biotree->right,i+1);	
	}
}*/
void findleaves(BTNodePtr root,int i)
{
	if(root->left==NULL&&root->right==NULL)
	{
		printf("%d %d\n",root->Data,i);
	}
	else
	{
		if(root->left!=NULL)findleaves(root->left,i+1);	
		if(root->right!=NULL)findleaves(root->right,i+1);	
	}
}




















