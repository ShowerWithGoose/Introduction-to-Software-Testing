#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
}BinTree;
BinTree* inserttree(BinTree** T, int num);
void preorderTravel(BinTree* T);
void destroy(BinTree* T);
int depth=1;
int main()
{
	int n,item;
	BinTree* root=NULL;
	scanf("%d",&n);
	int i;
	scanf("%d",&item);
	inserttree(&root,item);
	for(i=1;i<n;i++)
	{
		scanf("%d",&item);
		inserttree(&root,item);	
	}
	preorderTravel(root);
	destroy(root);
	return 0;
}
BinTree* inserttree(BinTree** T, int num)
{
	if((*T)==NULL)
	{
		(*T)=(BinTree*)malloc(sizeof(BinTree));
		(*T)->data=num;
		(*T)->lchild=(*T)->rchild=NULL; 
	}
	else if((*T)->data>num)
	{
		inserttree(&(*T)->lchild,num);
	}
	else
	{
		inserttree(&(*T)->rchild,num);
	}
	return *T;
}
void preorderTravel(BinTree* T)
{
	if(T==NULL)
	{
		return;
	}
	else if(T->lchild==NULL&&T->rchild==NULL)
	{
		printf("%d %d\n",T->data,depth);
	}
	depth++;
	preorderTravel(T->lchild);
	preorderTravel(T->rchild);
	depth--;
}
void destroy(BinTree* T)
{
	if(T!=NULL)
	{
		destroy(T->lchild);
		destroy(T->rchild);
		free(T);
	}
}



