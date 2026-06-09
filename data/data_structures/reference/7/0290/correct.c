#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num,high;
	struct node *lchild,*rchild;
} *root,*p,*k;
int h=1;
void comp(int m)
{
	if(m>=p->num)
	{
		if(p->rchild==NULL)
		{
			h++;
			k=(struct node *)malloc(sizeof(struct node));
			k->num=m;
			k->high=h;
			k->lchild=NULL;
			k->rchild=NULL;
			p->rchild=k;
		}
		else
		{
			h++;
			p=p->rchild;
			comp(m);
		}
	}
	else if(m<p->num)
	{
		if(p->lchild==NULL)
		{
			h++;
			k=(struct node *)malloc(sizeof(struct node));
			k->num=m;
			k->high=h;
			k->lchild=NULL;
			k->rchild=NULL;
			p->lchild=k;
		}
		else
		{
			h++;
			p=p->lchild;
			comp(m);
		}
	}
}
void VISIT(struct node *t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->num,t->high);
}
void postorder(struct node *t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		VISIT(t);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int m;
		scanf("%d",&m);
		if(root==NULL)
		{
			root=(struct node *)malloc(sizeof(struct node));
			root->num=m;
			root->high=1;
			root->lchild=NULL;
			root->rchild=NULL;
			p=root;
		}
		else
		{
			comp(m);
			h=1;
			p=root;
		}
	}
	postorder(root);
	return 0;
}

