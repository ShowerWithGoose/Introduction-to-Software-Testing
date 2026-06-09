#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int Data;
	struct tree* left,* right;
};
typedef struct tree BTNode,*BTNodePtr;
BTNodePtr insert_tree(int data,BTNodePtr biotree );
void findleaves(BTNodePtr biotree,int i);
int main()
{
	BTNodePtr biotree=NULL;
	int n,i,data;scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data);
		biotree=insert_tree(data,biotree);
	}
	findleaves(biotree,1);
	return 0;
}
BTNodePtr insert_tree(int data,BTNodePtr biotree)
{
	if(biotree==NULL)
	{
		biotree=(BTNodePtr)malloc(sizeof(BTNode));
		biotree->Data=data;
		biotree->left=biotree->right=NULL;
	}
	else if(data< biotree->Data)
		biotree->left=insert_tree(data,biotree->left);
	else if(data>=biotree->Data)
		biotree->right=insert_tree(data,biotree->right);
	return biotree;
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
void findleaves(BTNodePtr biotree,int i)
{
	if(biotree->left==NULL&&biotree->right==NULL)
	{
		printf("%d %d\n",biotree->Data,i);
	}
	else
	{
		if(biotree->left!=NULL)findleaves(biotree->left,i+1);	
		if(biotree->right!=NULL)findleaves(biotree->right,i+1);	
	}
}




















