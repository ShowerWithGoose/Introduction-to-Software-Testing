#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int num;
	int flag;
	struct tree *lchild;
	struct tree *rchild;
};

struct tree *list=NULL;
int main ()
{
	int n,i,a;
	int top=-1;
	struct tree *p,*q,*r;
	struct tree *stack[1000];
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++)
	{
		scanf ("%d",&a);
		p=(struct tree *)malloc(sizeof (struct tree));
		p->num=a;
		p->lchild=NULL;
		p->rchild=NULL;
		p->flag=1;
		
		if (list==NULL)
			list=p;

		else
		{
			q=list;
			while(1)
			{
				p->flag++;
				if (a<q->num)
				{
					if (q->lchild==NULL)
					{
						q->lchild=p;
						break;
					}
					else
						q=q->lchild;
				}
				else
				{
					if (q->rchild==NULL)
					{
						q->rchild=p;
						break;
					}
					else
						q=q->rchild;
				}
			}
		}	
//		printf ("%d %d\n",p->num,p->flag);
	}
// All these above are right	
//以下是中序遍历
	r=list;
	while (!(r==NULL&&top==-1))
	{
		if (r!=NULL)
		{
			stack[++top]=r;
			r=r->lchild;
		}
		else
		{
			r=stack[top--];
			if (r->lchild==NULL&&r->rchild==NULL)
				printf ("%d %d\n",r->num,r->flag);
			r=r->rchild;
		}
	}

	return 0;
}
