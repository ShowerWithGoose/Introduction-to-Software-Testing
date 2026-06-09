#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cnt=1;

typedef struct node{
	int data;
	int depth;
	struct node *lchild;
	struct node *rchild;
}*Tlink,Tnode;

Tlink insertTree(Tlink p,int item)
{
	if(p==NULL)
	{
		p=(Tlink)malloc(sizeof(Tnode));
		p->data=item;
		p->depth=cnt;
		p->lchild=NULL;
		p->rchild=NULL;
		cnt=1;
	}
	else if(item<p->data)
	{
		cnt++;
		p->lchild=insertTree(p->lchild,item);
	}
	else if(item>=p->data)
	{
		cnt++;
		p->rchild=insertTree(p->rchild,item);
	}
	return p;
}

void visit(Tlink p)
{
	printf("%d %d\n",p->data,p->depth);
}

void inorder(Tlink p)
{
	Tlink stack[200];
	int top=-1;
	do{
		for(;p!=NULL;p=p->lchild)
		{
			stack[++top]=p;
		}
		p=stack[top--];
		if(p->lchild==NULL&&p->rchild==NULL)
		visit(p);
		p=p->rchild;
	}while(!(p==NULL&&top==-1));
}

int main()
{
	int n,i;
	scanf("%d",&n);
	Tlink root=NULL;
	int hold;
	for(i=0;i<n;i++)
	{
		scanf("%d",&hold);
		root=insertTree(root,hold);
	}
	inorder(root);

	return 0;
 }

