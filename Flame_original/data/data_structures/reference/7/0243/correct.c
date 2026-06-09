#include<stdio.h>//×Ô¼º¶ÀÁ¢³¢ÊÔ  
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct no_de
{
	int data;
	struct no_de *lchild;
	struct no_de *rchild;
	int depth;
}TNode,*Tree;
int n;

void insertBST(Tree *T,int m,int depth)
{
	if(*T==NULL)
	{
		(*T)=(Tree)malloc(sizeof(TNode));
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
		(*T)->depth=depth;
		(*T)->data=m;
	}
	else
	{
		if(m<(*T)->data)
		{
			insertBST(&(*T)->lchild,m,depth+1);
		}
		else
		{
			insertBST(&(*T)->rchild,m,depth+1);
		}
	}
}

void traverse(Tree T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		traverse(T->lchild);
		if(T->lchild==NULL && T->rchild==NULL)
		{
			printf("%d %d\n",T->data,T->depth);
		}
		traverse(T->rchild);
	}
}

int main()
{
	scanf("%d",&n);
	int m;
	int i;
	Tree root;
	root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		insertBST(&root,m,1);
	}
	traverse(root);
	return 0;
}

