#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
}tree,*Tree;
int m,i,n,depth=1;
Tree root=NULL;
void visit(Tree t)
{
	printf("%d %d\n",t->val,t->depth);
}
void sequence(Tree t)
{
    if(t!=NULL){
        sequence(t->left);
        if(t->left==NULL && t->right==NULL)	visit(t);    
        sequence(t->right);
    }
}
void InsertBST(Tree *t,int value,int depth);
int main()
{	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		InsertBST(&root,m,1);
	}
	sequence(root);
	return 0;
}

void InsertBST(Tree *t,int value,int depth) 
{
	if(*t==NULL)
	{
		*t=(Tree)malloc(sizeof(Tree));
		(*t)->left=(*t)->right=NULL;
		(*t)->val=value;
		(*t)->depth=depth;
	}
	else if(value<(*t)->val)
	{
		InsertBST(&((*t)->left),value,depth+1);
	} 
	else
	{
		InsertBST(&((*t)->right),value,depth+1);
	} 
}


