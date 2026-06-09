#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct tree{
	int data;
	struct tree *lchild;
	struct tree *rchild;
}*PTree,Tree;

void order(PTree t,int i)
{
	if(t!=NULL)
	{
		if(t->lchild!=NULL)
		{
			i++;
			order(t->lchild,i);
			i--;
		}
		if(t->rchild!=NULL)
		{
			i++;
			order(t->rchild,i);
			i--;
		}
		else if(t->lchild==NULL&&t->rchild==NULL)
		{
			printf("%d %d\n",t->data,i);
		}
	}
}

PTree root=NULL;
PTree p;

int main()
{	
	int a,n,j,k;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		scanf("%d",&a);
		if(root==NULL)
		{
			root=(PTree)malloc(sizeof(Tree));
			root->data=a;
			root->lchild=NULL;
			root->rchild=NULL;
		}
		else
		{
			p=root;
			while(!(a<p->data&&p->lchild==NULL||a>=p->data&&p->rchild==NULL))
			{
				if(a<p->data)
				{
					p=p->lchild;
				}
				else
				{
					p=p->rchild;
				}
			}
			if(a<p->data)
			{
				p->lchild=(PTree)malloc(sizeof(Tree));
				p->lchild->data=a;
				p->lchild->lchild=NULL;
				p->lchild->rchild=NULL;
			}
			else
			{
				p->rchild=(PTree)malloc(sizeof(Tree));
				p->rchild->data=a;
				p->rchild->lchild=NULL;
				p->rchild->rchild=NULL;
			}
		}
	}
	
	p=root;
	order(p,1);
	
	return 0;
}

