#include<stdio.h>
#include<string.h>

typedef struct node{
	int data;
	int depth;
	struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE p=NULL;

BTREE insertbst(BTREE t,int item,int item2)
{
	if(t==NULL)
	{
		t=(BTREE)malloc(sizeof(BTNode));
		t->data=item;
		t->depth=item2;
		t->lchild=NULL;
		t->rchild=NULL;	
	}
	else if(item<(t->data))
		t->lchild=insertbst(t->lchild,item,item2+1);
	else
		t->rchild=insertbst(t->rchild,item,item2+1);
	
	return t;	
}

void preorder(BTREE t) 
{
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
			printf("%d %d\n",t->data,t->depth);
		preorder(t->lchild); 
		preorder(t->rchild); 
	}	
} 

int main()
{
	int n,i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		p=insertbst(p,num,1);
	}
	preorder(p);
	
	return 0;
}

