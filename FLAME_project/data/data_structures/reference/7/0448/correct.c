#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	int rank;
	struct node *lchild,*rchild;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
void insert(int item);
void leaf(BTNodeptr p);
int main()
{
	int n,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf(" %d",&x);
		insert(x); 
	} 
	leaf(root);
	return 0;
}
void insert(int item)
{
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->data=item;
	p->rank=1;
	p->lchild=NULL;
	p->rchild=NULL;
	if(root==NULL)
	{
		root=p;
		return;
	}
	q=root;
	while(1)
	{
		if(item<q->data)
		{
			p->rank+=1;
			if(q->lchild==NULL)
			{
				q->lchild=p;
				break;
			}
			else
			{
				q=q->lchild;
			}
		}
		else if(item>=q->data)
		{
			p->rank+=1;
			if(q->rchild==NULL)
			{
				q->rchild=p;
				break;
			}
			else
			{
				q=q->rchild;
			}
		}	
	}	
}
void leaf(BTNodeptr p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			printf("%d %d\n",p->data,p->rank);
			return;
		}
		leaf(p->lchild);
		leaf(p->rchild);
	}
}

