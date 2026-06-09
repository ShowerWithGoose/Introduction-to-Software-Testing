#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *lchild,*rchild;
} bst;
typedef bst* bstPtr;
bstPtr insert(bstPtr p,int b_num)
{
	if(p==NULL)
	{
		p = (bstPtr)malloc(sizeof(bst));
		p->data=b_num;
		p->lchild=p->rchild=NULL;
	}
	else if(b_num<p->data)
	{
		p->lchild = insert(p->lchild,b_num);
	}
	else if(b_num>=p->data)
	{
		p->rchild = insert(p->rchild,b_num);
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
	int n,i,data;
	bstPtr root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root = insert(root,data);
	}
	inorder(root,1);
	return 0;
}

