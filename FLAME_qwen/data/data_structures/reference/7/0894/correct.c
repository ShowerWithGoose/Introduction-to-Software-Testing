#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct tree
{
	struct tree *lchild,*rchild;
	int num;
};
void visit_leaf(struct tree*,int depth);
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	struct tree *head,*p,*q;
	head=(struct tree *)malloc(sizeof(struct tree *));
	p=head;
	scanf("%d",&k);
	head->num=k;
	head->lchild=NULL;
	head->rchild=NULL;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&k);
		while(1)
		{
			if(k<p->num)
			{
				if(p->lchild==NULL)
				{
					p->lchild=(struct tree *)malloc(sizeof(struct tree *));
					p=p->lchild;
					p->num=k;
					p->lchild=NULL;
					p->rchild=NULL;
					p=head;
					break;
				}
				else p=p->lchild;
			}
			else
			{
				if(p->rchild==NULL)
				{
					p->rchild=(struct tree *)malloc(sizeof(struct tree *));
					p=p->rchild;
					p->num=k;
					p->lchild=NULL;
					p->rchild=NULL;
					p=head;
					break;
				}
				else p=p->rchild;
			}
		}
	}
	visit_leaf(head,1);
}
void visit_leaf(struct tree* p,int depth)
{
	if(p->lchild==NULL&&p->rchild==NULL)printf("%d %d\n",p->num,depth);
	else
	{
		if(p->lchild!=NULL)visit_leaf(p->lchild,depth+1);
		if(p->rchild!=NULL)visit_leaf(p->rchild,depth+1);
	}
}

