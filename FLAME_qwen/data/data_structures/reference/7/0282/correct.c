#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int data;
	int height;
	struct node *lchild;
	struct node *rchild;
}Node;
Node *T=NULL;
void Insert(int item);
void preOrder(Node *T);
void VISIT(Node *p);
int main()
{
	int n,item;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&item);
		Insert(item);
	}
	preOrder(T);
	return 0;
}
void Insert(int item)
{
	Node *p,*q;
	int num=1;
	p=(Node *)malloc(sizeof(Node));
	p->data=item;
	p->lchild=p->rchild=NULL;
	if(T==NULL)
	{
		p->height=1;
		T=p;
		return;
	}
	q=T;
	while(1)
	{
		num++;
		if(item<q->data)
		{
			if(q->lchild!=NULL)
			q=q->lchild;
			else
			{
				p->height=num;
				q->lchild=p;
				break;
			}
		}
		else
		{
			if(q->rchild!=NULL)
			q=q->rchild;
			else
			{
				p->height=num;
				q->rchild=p;
				break;
			}
		}
	}
}
void preOrder(Node *T)
{
	Node *stack[200],*p=T;
	int top=-1;
	if(T!=NULL)
	{
		do
		{
			while(p!=NULL)
			{
				VISIT(p);
				stack[++top]=p;
				p=p->lchild;
			}
			p=stack[top--];
			p=p->rchild;
		}while(p!=NULL||top!=-1);
	}
}
void VISIT(Node *p)
{
	if(p->lchild==NULL&&p->rchild==NULL)
	{
		printf("%d %d\n",p->data,p->height);
	}
}

