#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct node
{
	int data;
	int depth;
	struct node *lchild,*rchild,*parent;
};
struct node* insertBST(struct node *p,int item)
{
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=item;
		p->depth=1;
		p->lchild=p->rchild=p->parent=NULL;
	}
	else if(item<p->data)
	{
		p->lchild=insertBST(p->lchild,item);
		p->lchild->parent=p; 
		p->lchild->depth=p->depth+1;
	}
	else if(item>=p->data)
	{
		p->rchild=insertBST(p->rchild,item);
		p->rchild->parent=p;
		p->rchild->depth=p->depth+1;
	}
	return p;
}
void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->data,t->depth);
		inorder(t->rchild);
	}
 } 
int main()
{
	struct node *root=NULL;
	int n,m,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=insertBST(root,m);
	}
	inorder(root);
	return 0;
}

