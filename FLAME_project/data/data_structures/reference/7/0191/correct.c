#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int high;
	struct node * lchild;
	struct node * rchild;
	int data;
};
struct node *q=NULL,*r=NULL;
struct node *insertT(struct node* p,int t,int l)
{
	l++;
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=t;
		p->lchild=NULL;
		p->rchild=NULL;
		p->high=l;
	}
	else
	{
		if(t<p->data)
		{
			p->lchild=insertT(p->lchild,t,l);
		}
		else if(t>=p->data)
		{
			p->rchild=insertT(p->rchild,t,l);
		}
	}
	return p;
}
void inorder(struct node * t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		if((t->lchild==NULL)&&(t->rchild==NULL))
		{
			printf("%d %d",t->data,t->high);
			printf("\n");
		}
		inorder(t->rchild);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int temp;
	int len;
	while(n--)
	{
		len=0;
		scanf("%d",&temp);
		r=insertT(r,temp,len);
		
	}
	inorder(r);
	
	return 0;
 } 

