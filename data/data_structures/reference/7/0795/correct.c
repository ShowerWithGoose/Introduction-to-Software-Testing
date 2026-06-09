#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct tree {
    int val;
    struct tree *left;
    struct tree *right;
    int dp;
}Tree,*Treep;
int m,i,n,dp=1;
Treep root=NULL;
void VISIT(Treep t)
{
	printf("%d %d\n",t->val,t->dp);
}
void inorder(Treep t)
{
    if(t!=NULL){
        inorder(t->left);
        if(t->left==NULL && t->right==NULL)	VISIT(t);
        inorder(t->right);
    }
}
void bst(Treep *t,int value,int dp);
int main()
{	
	int EX[30];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		bst(&root,m,1);
	}
	for(i=0;i<100;i++)
	{
		if(EX[i]!=0)
		continue;
		EX[i]=m;
	}
	inorder(root);
	return 0;
}
void bst(Treep *t,int value,int dp)
{
	if(*t==NULL)
	{
		*t=(Treep)malloc(sizeof(Treep));
		(*t)->left=(*t)->right=NULL;
		(*t)->val=value;
		(*t)->dp=dp;
	}
	else if(value<(*t)->val)
	{
		bst(&((*t)->left),value,dp+1);
	} 
	else
	{
		bst(&((*t)->right),value,dp+1);
	} 
}

