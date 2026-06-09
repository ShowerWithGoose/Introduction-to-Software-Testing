#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct TreeNode{
	int val;
	int depth;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree,*PTree;

PTree root = NULL; 
void Vist(PTree t);
void order(PTree t);
void InsertBST(PTree *t, int num, int depth);
int main()
{
	int n, num;
	scanf("%d",&n);
	int depth = 1;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&num);
		InsertBST(&root, num, depth);
	}
	order(root);
	return 0;
 } 

void Vist(PTree t)
{
	if(t!=NULL)
		printf("%d %d\n",t->val,t->depth);
}

void order(PTree t)
{
	if(t!=NULL)
	{
		if(t->left == NULL && t->right == NULL)
			Vist(t);
		else{
			order(t->left);
			order(t->right);
		}
	}
}

void InsertBST(PTree *t, int num, int depth)
{
	if(*t == NULL)
	{
		*t = (PTree)malloc(sizeof(PTree));
		(*t)->val = num;
		(*t)->depth = depth;
		(*t)->left = (*t)->right = NULL;
	}
	else if(num < (*t)->val)
	{
		InsertBST(&((*t)->left), num, depth+1);
	}
	else
	{
		InsertBST(&((*t)->right), num, depth+1);
	}
}

