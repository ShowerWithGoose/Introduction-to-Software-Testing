#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *lchild;
	struct node *rchild;
	int dep;
}BTNode,*pBTNode;
void insert(int x,pBTNode list)
{
	pBTNode p;
	p=list;

		pBTNode n=(pBTNode)malloc(sizeof(BTNode));
		n->num=x;
		n->rchild=NULL;
		n->lchild=NULL;
		while(1)
		{
			if(x<p->num)
			{
				if(p->lchild==NULL)
				{
					p->lchild=n;break;
				}
				else p=p->lchild;
			}
			else
			{
				if(p->rchild==NULL)
				{
					p->rchild=n;break;
				}
				else p=p->rchild;
			}
		}	
	return;
}
void visit(pBTNode t,int d)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	printf("%d %d\n",t->num,d);
	return;
}
void inorder(pBTNode list,int k)
{
	pBTNode t=list;
	if(t!=NULL)
	{
		inorder(t->lchild,k+1);
		visit(t,k);
		inorder(t->rchild,k+1);
	}
	return;
}
int main()
{
	int i,n,op;
	pBTNode l;
	scanf("%d",&n);
	scanf("%d",&op);
	l=(pBTNode)malloc(sizeof(BTNode));
	l->rchild=NULL;
	l->lchild=NULL;
	l->num=op;
	for(i=1;i<n;i++)
	{
		scanf("%d",&op);
		insert(op,l);
	}
	inorder(l,1);
	return 0;
}

