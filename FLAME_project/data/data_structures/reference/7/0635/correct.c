#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct TreeNode_s
{
	int val;
	struct TreeNode_s * right;
	struct TreeNode_s * left;
	int height;
}TreeNode;
void ConductTree(TreeNode* tree);
void SearchTree(TreeNode * tree);
TreeNode* InsertTree(int * pheight,int m,TreeNode* tree);
TreeNode * SetTree();
int main()
{
	TreeNode * tree=SetTree();
	SearchTree(tree);
	return 0;
} 
TreeNode * SetTree()
{
	TreeNode* tree=NULL;
	int n,i,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		int height=1;
		tree=InsertTree(&height,m,tree);
	}
	return tree;
}
TreeNode* InsertTree(int * pheight,int m,TreeNode* tree)
{
	if(!tree) 
	{
		tree=(struct TreeNode*)malloc(sizeof(TreeNode));
		tree->left=NULL;
		tree->right=NULL;
		tree->val=m;
		tree->height=*pheight;
	}
	else
	{
		++*pheight;
		if(m<tree->val) tree->left=InsertTree(pheight,m,tree->left);
		else if(m>=tree->val) tree->right=InsertTree(pheight,m,tree->right);
	}
	return tree;
}
void SearchTree(TreeNode * tree)
{
	if(!tree)
	return;
	SearchTree(tree->left);
	SearchTree(tree->right);
	ConductTree(tree);
	return;
}
void ConductTree(TreeNode* tree)
{
	if((!tree->left)&&(!tree->right))
	printf("%d %d\n",tree->val,tree->height);
	return;
}


