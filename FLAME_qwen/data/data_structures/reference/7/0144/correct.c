#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tree
{
	int data;
	int high;
	struct tree *lchild,*rchild;
};
typedef struct tree node;
typedef struct tree *nodeptr;

void preoder(nodeptr r)
{
	if(r){
	
	if(r->lchild==NULL && r->rchild==NULL)
	{
	    printf("%d %d\n",r->data,r->high);
	}
	preoder(r->lchild);
	preoder(r->rchild);
}
}

int main()
{
	nodeptr list=NULL,p=NULL,q=NULL;

	int sum;
	int num[200];
	int i;
	int highnow;

	scanf("%d",&sum);
	for(i=0; i<sum; i++)
	{
		scanf("%d",&num[i]);

		//建立结点
		p=(nodeptr)malloc(sizeof(node));
		p->data=num[i];
		p->high=0;
		p->lchild=NULL;
		p->rchild=NULL;

		//p指向当前结点
		if(list==NULL)
		{
			list=p;
			p->high=1;
		}
		else
		{
			q=list; //q为活动结点
			while(1)
			{
				highnow=q->high;
				if(p->data>=q->data)
				{
					if(q->rchild==NULL)
					{
						q->rchild=p;
						p->high=highnow+1;
						break;
					}
					else
					{
						q=q->rchild;
					}
				}
				else if(p->data<q->data)
				{
					if(q->lchild==NULL)
					{
						q->lchild=p;
						p->high=highnow+1;
						break;
					}
					else
					{
						q=q->lchild;
					}
				}
			}
		}
	}
	preoder(list);
	return 0;
}




