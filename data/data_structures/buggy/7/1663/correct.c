#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int x;
	int count;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr root=NULL;
void createtree(int a)
{
	BTNodeptr p,q;
	q=(BTNodeptr)malloc(sizeof(BTNode));
	q->x=a;
	q->count=1;
	q->lchild=NULL;
	q->rchild=NULL;
	if(root==NULL)
	{
		root=q;
	}
	else
	{
		p=root;
		while(1)
		{
			if(a<p->x)
			{
				if(p->lchild==NULL)
				{
					p->lchild=q;
					q->count++;
					break;
				}
				else
				{
					p=p->lchild;
					q->count++;
				}
			}
			else if(a>=p->x)
			{
				if(p->rchild==NULL)
				{
					p->rchild=q;
					q->count++;
					break;
				}
				else
				{
					p=p->rchild;
					q->count++;
				}
			}
		}
	}
}
void inorder(BTNodeptr t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		inorder(t->rchild);
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			printf("%d %d\n",t->x,t->count);
		}
	}
}
int main()
{
	int i,n,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		createtree(a);
	}
	inorder(root);
	return 0;
} 

