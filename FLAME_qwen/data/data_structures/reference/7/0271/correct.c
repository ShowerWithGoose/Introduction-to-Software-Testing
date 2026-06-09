#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int depth;
	struct node *lchild,*rchild;
}Tree,*Ptree;
int height = 0;
Ptree insertBST(Ptree p,int item,int depth)
{
	if(p == NULL)
	{
		p = (Ptree)malloc(sizeof(Tree));
		p->data = item;
		p->depth = depth;
		p->lchild = p->rchild = NULL;
	}
	else if(item < p->data)
		p->lchild = insertBST(p->lchild,item,depth + 1);
	else if(item >= p->data)
		p->rchild = insertBST(p->rchild,item,depth + 1);
	return p;
}
void preorder(Ptree t)
{	
	if(t != NULL)
	{
		if(t->lchild == NULL && t->rchild == NULL)	
			printf("%d %d\n",t->data,t->depth);
		preorder(t->lchild);
		preorder(t->rchild);
		height ++;
	}
	
}
int main()
{
	int n,i;
	int item;
	Ptree root = NULL;
	scanf("%d",&n);
	for(i = 0;i < n; i++)
	{
		scanf("%d",&item);
		root = insertBST(root,item,1);
	}
	preorder(root);
	return 0;
} 

