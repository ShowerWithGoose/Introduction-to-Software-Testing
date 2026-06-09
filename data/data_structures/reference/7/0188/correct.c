#include<stdio.h>
struct node
{
	int data;
	struct node *lchild,*rchild;
}; 
typedef struct node bstnode,*bstnodeptr;
bstnodeptr insertbst(bstnodeptr p,int item)
{
	if(p==NULL)
	{
		p=(bstnodeptr)malloc(sizeof(bstnode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
	{
		p->lchild=insertbst(p->lchild,item);
	}
	else if(item>=p->data)
	{
		p->rchild=insertbst(p->rchild,item);
	}
	else;
	return p;
}
int sea(bstnodeptr p,int high)
{
	if(p!=NULL)
	{
		sea(p->lchild,high+1);
		sea(p->rchild,high+1);
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			printf("%d %d\n",p->data,high);
		}
		//printf("%d %d\n",p->data,high);
	}
	
}
int main()
{
	int count;
	scanf("%d",&count);
	bstnodeptr root=NULL;
	int i=1;
	for(;i<=count;i++)
	{
		int n;
		scanf("%d",&n);
		root=insertbst(root,n); //重点，别少了等于号 
	}
	sea(root,1);
	return 0;
}


