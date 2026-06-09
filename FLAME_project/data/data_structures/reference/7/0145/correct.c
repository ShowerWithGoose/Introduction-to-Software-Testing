#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>


typedef struct TreeNode{
	int data;
	int depth;
	struct TreeNode *left;
	struct TreeNode *right;
}BST;

BST *root;


BST *CreateTree(BST *tree, int t, int d)
{
	d++;
	
	BST *bst = (BST*)malloc(sizeof(BST));
	bst->data = t;
	bst->left = NULL;
	bst->right = NULL;
	bst->depth = d;
	
	if(tree == NULL){
		tree = bst;
	}
	
	else if(t < tree->data){
		tree->left = CreateTree(tree->left, t, d);
		}
	else if(t >= tree->data){
		tree->right = CreateTree(tree->right, t, d);
	}		
	return tree;
}

void PrintLeaves(BST *tree){
	if( tree )
	{
		
		if( !tree->left && !tree->right){
			printf("%d %d\n", tree->data, tree->depth);
		} 
		PrintLeaves ( tree->left );
		PrintLeaves ( tree->right );
	}
}

int main()
{
	int n, hold;
	BST *root = NULL;
	int i;
	scanf("%d",&n);
	for( i=0; i<n; i++)
	{
		int d = 0;
		scanf("%d", &hold);
		root = CreateTree(root, hold,d);
	} 
	PrintLeaves(root);
	
	
	return 0;
}


