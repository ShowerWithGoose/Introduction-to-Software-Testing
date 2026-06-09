#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int number,depth;
	struct node *lchild,*rchild;
}unit;
unit* list;
void insert(int a)
{
	struct node* p0=list;
	struct node* p=(unit*)malloc(sizeof(unit));
	p->lchild=NULL;p->number=a;p->rchild=NULL;
	while(1)
	{
		if(a<p0->number)
		{
			if(p0->lchild==NULL)
			{p0->lchild=p;p->depth=p0->depth+1;break;}
			else	
				p0=p0->lchild;
		}
		else
		{
			if(p0->rchild==NULL)
			{p0->rchild=p;p->depth=p0->depth+1;break;}	
			else
				p0=p0->rchild;
		}	
	}
}
void preorder(unit* p)
{
	if(p!=NULL)
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			printf("%d %d\n",p->number,p->depth);	
		}
		preorder(p->lchild);
		preorder(p->rchild);				
	}	
}
int main()
{
	int n,a;
	scanf("%d",&n);
	scanf("%d",&a);
	list=(unit*)malloc(sizeof(unit));
	list->number=a;list->lchild=NULL;list->rchild=NULL;list->depth=1;
	for(int i=1;i<n;i++)
	{int m;scanf("%d",&m);insert(m);}
	preorder(list);
 } 



