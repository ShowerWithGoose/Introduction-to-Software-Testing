#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int n;
	int depth;
	struct Tree *lchild,*rchild;
}*root,*p;
void preorder(struct Tree *root);
int main()
{
	int n,i,num;
	scanf("%d",&n);
	root=(struct Tree *)malloc(sizeof(struct Tree));
	root->lchild=root->rchild=NULL;
	root->depth=1;
	if(n!=0)
	{
		scanf("%d",&num);
		root->n=num; 
	}
	p=root;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&num);
		p=root;
		while(1)
		{
			if(num>=p->n&&p->rchild==NULL)
			{
				p->rchild=(struct Tree *)malloc(sizeof(struct Tree));
				p->rchild->n=num;
				p->rchild->depth=p->depth+1;
				p->rchild->lchild=NULL;
				p->rchild->rchild=NULL;
				break;
			}
			else if(num<p->n&&p->lchild==NULL)
			{
				p->lchild=(struct Tree *)malloc(sizeof(struct Tree));
				p->lchild->n=num;
				p->lchild->depth=p->depth+1;
				p->lchild->lchild=NULL;
				p->lchild->rchild=NULL;
				break;
			}
			else if(num>=p->n&&p->rchild!=NULL) p=p->rchild;
			else if(num<p->n&&p->lchild!=NULL) p=p->lchild;
		}
	}
	preorder(root);
	return 0;
} 

void preorder(struct Tree *root)
{
	struct Tree *p;
	p=root;
	if(p!=NULL)
	{
		if(p->lchild==NULL&&p->rchild==NULL)
			printf("%d %d\n",p->n,p->depth);		
		preorder(p->lchild);
		preorder(p->rchild);
	}
} 
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/

