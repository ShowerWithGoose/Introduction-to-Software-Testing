#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node BTnode,*BTnodeptr;

BTnodeptr insertBST(BTnodeptr p,int item)
{
	if(p==NULL)
	{
		p=(BTnodeptr)malloc(sizeof(BTnode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
		p->lchild=insertBST(p->lchild,item);
	else
		p->rchild=insertBST(p->rchild,item);
	return p;
}

int cdeep=0;
void PREORDER(BTnodeptr T,int deep)
{
	if(T!=NULL)
	{
		deep++;
		if(T->lchild==NULL&&T->rchild==NULL)
			printf("%d %d\n",T->data,deep);
		PREORDER(T->lchild,deep);
		PREORDER(T->rchild,deep);
	}
}

int main()
{
	int i,item,n;
	BTnodeptr root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insertBST(root,item);
	}
	PREORDER(root,cdeep);
	return 0;
}



