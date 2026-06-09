#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct node{	
	int data;
	struct node *lchild;
	struct node *rchild;
	int floor;	
}*BTP,BT;
BTP Build(BTP q,int item,int height);
void proorder(BTP q)
{
	if(q==NULL)
	return ;
	else if(q->lchild==NULL&&q->rchild==NULL)
	printf("%d %d\n",q->data,q->floor); 
	proorder(q->lchild);
	proorder(q->rchild);	
}
int main()
{
    BTP head;
	int item,i;
	scanf("%d",&n);
	scanf("%d",&item);
	head=(BTP )malloc(sizeof(BT));
	head->data=item;
	head->floor=1;
	head->lchild=NULL;
	head->rchild=NULL;
    for(i=2;i<=n;i++)
   {
	scanf("%d",&item);
	Build(head,item,1);	
   }
   proorder(head);	
}
BTP Build(BTP q,int item,int height)
{
	if(q!=NULL)
	{
		if(q->data<=item)
		q->rchild=Build(q->rchild,item,height+1);
		else
		q->lchild=Build(q->lchild,item,height+1);
	}
	else
	{
		q=(BTP)malloc(sizeof(BT));
		q->data=item;
		q->floor=height;
		q->lchild=NULL;
		q->rchild=NULL;
	}
	return q;
}

