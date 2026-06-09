#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include<ctype.h>
#define ll long long //9223372036854775807（>10^18）   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double


typedef struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
    int depth;
}Tree,*tree;
int m,i,n,depth=1;
tree root=NULL;
void VISIT(tree t);
void inorder(tree t);
void InsertBST(tree *t,int value,int depth);
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

void VISIT(tree t)// 访问结点 
{
	printf("%d %d\n",t->data,t->depth);
}


void inorder(tree t)
{
    if(t!=NULL){
        inorder(t->lchild);
        if(t->lchild==NULL && t->rchild==NULL)	VISIT(t);      // 访问t指的叶子结点 
        inorder(t->rchild);
    }
}


void InsertBST(tree *t,int value,int depth) //构造BST 
{
	if(*t==NULL)
	{
		*t=(tree)malloc(sizeof(tree));
		(*t)->lchild=(*t)->rchild=NULL;
		(*t)->data=value;
		(*t)->depth=depth;
	}
	else if(value<(*t)->data)
	{
		InsertBST(&((*t)->lchild),value,depth+1);
	} 
	else
	{
		InsertBST(&((*t)->rchild),value,depth+1);
	} 
}



