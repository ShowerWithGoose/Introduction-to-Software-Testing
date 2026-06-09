#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *lchild,*rchild;
} bst;
typedef bst* bstPtr;
bstPtr insert(bstPtr p,int data0)
{
	if(p==NULL)
	{
		p = (bstPtr)malloc(sizeof(bst));
		p->data=data0;
		p->lchild=p->rchild=NULL;
	}
	else if(data0<p->data)
	{
		p->lchild = insert(p->lchild,data0);
	}
	else if(data0>=p->data)
	{
		p->rchild = insert(p->rchild,data0);
	}
	return p;
}
void inorder(bstPtr t,int height)
{
	if(t!=NULL)
	{
		inorder(t->lchild,height+1);
		if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->data,height);
		inorder(t->rchild,height+1);
	}
 } 
int main()
{
	int n,i,tep;
	bstPtr root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tep);
		root = insert(root,tep);
	}
	inorder(root,1);
	return 0;
}

