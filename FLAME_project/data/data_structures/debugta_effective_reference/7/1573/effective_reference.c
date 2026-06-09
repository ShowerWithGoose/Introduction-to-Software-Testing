#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *lchild,*rchild;
} bst;
typedef bst* bstPtr;
bstPtr insert(bstPtr p,int insert_data)
{
	if(p==NULL)
	{
		p = (bstPtr)malloc(sizeof(bst));
		p->data=insert_data;
		p->lchild=p->rchild=NULL;
	}
	else if(insert_data<p->data)
	{
		p->lchild = insert(p->lchild,insert_data);
	}
	else if(insert_data>=p->data)
	{
		p->rchild = insert(p->rchild,insert_data);
	}
	return p;
}
void inorder(bstPtr root,int height)
{
	if(root!=NULL)
	{
		inorder(root->lchild,height+1);
		if(root->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",root->data,height);
		inorder(root->rchild,height+1);
	}
 } 
int main()
{
	int n,i,tmp;
	bstPtr root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		root = insert(root,tmp);
	}
	inorder(root,1);
	return 0;
}

