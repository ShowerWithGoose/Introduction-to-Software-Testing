#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
}Tree,*Treep;
int m,i,n,depth=1;
Treep root=NULL;
void VISIT(Treep t)// 访问结点
{
	printf("%d %d\n",t->val,t->depth);
}
void inorder(Treep t)
{
    if(t!=NULL){
        inorder(t->left);
        if(t->left==NULL && t->right==NULL)	VISIT(t);      // 访问t指的叶子结点
        inorder(t->right);
    }
}
void InsertBST(Treep *t,int value,int depth);
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		InsertBST(&root,m,1);
	}
	inorder(root);
	return 0;
}

void InsertBST(Treep *t,int value,int depth) //构造BST
{
	if(*t==NULL)
	{
		*t=(Treep)malloc(sizeof(Treep));
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

