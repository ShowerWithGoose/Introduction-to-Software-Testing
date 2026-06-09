#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data,high;
	struct node* lchild,*rchild;
}BST;

void insert(BST **T,int num)
{
	BST *p,*q;
	p=(BST*)malloc(sizeof(BST));
	p->data=num;
	p->high =1;
	p->lchild=NULL;
	p->rchild =NULL;
	if(*T==NULL)
	{
		*T=p;	
	}	
	else
	{
		q=*T;
		while(1)
		{
			p->high ++;
			if(p->data <q->data )
			{
				if(q->lchild !=NULL)
				{
					q=q->lchild;
				}
				else
				{
					q->lchild=p;
					break;
				}
			}
			else
			{
				if(q->rchild !=NULL)
				{
					q=q->rchild;
				}
				else
				{
					q->rchild=p;
					break;
				}
			}
		}
	}
}

void output(BST *T)
{
	if(T->lchild !=NULL)
	{
		output(T->lchild );
	}
	if(T->rchild !=NULL)
	{
		output(T->rchild );
	}
	if(T->lchild ==NULL&&T->rchild==NULL)
	{
		printf("%d %d\n",T->data,T->high);
		return;
	}
}

int main()
{
	BST *T=NULL;
	int n,i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&T,num);
	}
	output(T);
	return 0;
}

