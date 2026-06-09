#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	int deep;
	struct node* lchild;
	struct node* rchild;
}NODE,*PNODE;

PNODE creat_tree(PNODE p,int num,int deep)
{
	if(p==NULL)
	{
		p=(PNODE)malloc(sizeof(NODE));
		p->data=num;
		p->deep=deep;
		p->lchild=p->rchild=NULL;
	}
	else if(num<p->data)
	{
		p->lchild=creat_tree(p->lchild,num,deep+1);
	}
	else if(num>=p->data)
	{
		p->rchild=creat_tree(p->rchild,num,deep+1);
	}
	return p;
}

void travel(PNODE r)
{
	if(r!=NULL)
	{
		travel(r->lchild);
		if(r->lchild==NULL&&r->rchild==NULL)
		{
			printf("%d %d\n",r->data,r->deep);
		}
		travel(r->rchild);
		//if(r->lchild==NULL&&r->rchild==NULL)
//		{
//			printf("%d %d\n",r->data,r->deep);
//		}
	}
}
int main()
{
	int n,i,num;
	PNODE root,p;
	root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		root=creat_tree(root,num,1);
	}
    travel(root);
	return 0;
}

