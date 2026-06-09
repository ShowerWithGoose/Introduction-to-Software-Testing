#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
	int data;
	int depth;
	struct node * lchild,*rchild;
};
struct node* t=NULL;
struct node* p,*q;
void preorder(struct node *tr);
void midorder(struct node *tr)
{
	if(tr!=NULL)
	{
		midorder(tr->lchild);
		if(tr->lchild==NULL&&tr->rchild==NULL)
		{
			printf("%d %d\n",tr->data,tr->depth);
		}
		midorder(tr->rchild);
	}
}
int main()
{
	int n;
	int de;
	int num;
	scanf("%d",&n);
	while(n--)
	{
		de=1;
		scanf("%d",&num);
		p=(struct node*)malloc(sizeof(struct node));
		p->data=num;
		p->lchild=NULL;
		p->rchild=NULL;
		if(t==NULL)
		{
			t=p;
			p->depth=de;
		} 
		else
		{
			q=t;
			while(1)
			{
				if(p->data<q->data)
				{
					if(q->lchild!=NULL)
					{
						q=q->lchild;
						de++;
					}
					else
					{
						q->lchild=p;
						p->depth=de+1;
						break;
					}
				}
				else
				{
					if(q->rchild!=NULL)
					{
						q=q->rchild;
						de++;
					}
					else
					{
						q->rchild=p;
						p->depth=de+1;
						break;
					}
				}
				
			} 
		}
			 
	}
	midorder(t);
	
}

